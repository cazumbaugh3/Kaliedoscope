//
// Created by Chuck Zumbaugh on 1/8/24.
//

#include "./KaliedoscopeJIT.h"

llvm::orc::KaleidoscopeJIT::KaleidoscopeJIT(std::unique_ptr<ExecutionSession> ES,
JITTargetMachineBuilder JTMB, DataLayout DL): ES(std::move(ES)), DL(std::move(DL)), Mangle(*this->ES, this->DL),
ObjectLayer(*this->ES,
            []() { return std::make_unique<SectionMemoryManager>(); }),
CompileLayer(*this->ES, ObjectLayer,
             std::make_unique<ConcurrentIRCompiler>(std::move(JTMB))),
MainJD(this->ES->createBareJITDylib("<main>")) {
    MainJD.addGenerator(
            cantFail(DynamicLibrarySearchGenerator::GetForCurrentProcess(
                    DL.getGlobalPrefix())));
    if (JTMB.getTargetTriple().isOSBinFormatCOFF()) {
        ObjectLayer.setOverrideObjectFlagsWithResponsibilityFlags(true);
        ObjectLayer.setAutoClaimResponsibilityForObjectSymbols(true);
    }
}

llvm::orc::KaleidoscopeJIT::~KaleidoscopeJIT() {
    if (auto Err = ES->endSession())
        ES->reportError(std::move(Err));
}

llvm::Expected<std::unique_ptr<llvm::orc::KaleidoscopeJIT>> llvm::orc::KaleidoscopeJIT::Create() {
auto EPC = SelfExecutorProcessControl::Create();
if (!EPC)
return EPC.takeError();

auto ES = std::make_unique<ExecutionSession>(std::move(*EPC));

JITTargetMachineBuilder JTMB(
        ES->getExecutorProcessControl().getTargetTriple());

auto DL = JTMB.getDefaultDataLayoutForTarget();
if (!DL)
return DL.takeError();

return std::make_unique<KaleidoscopeJIT>(std::move(ES), std::move(JTMB),
        std::move(*DL));
}

llvm::Error llvm::orc::KaleidoscopeJIT::addModule(ThreadSafeModule TSM, ResourceTrackerSP RT) {
    if (!RT)
        RT = MainJD.getDefaultResourceTracker();
    return CompileLayer.add(RT, std::move(TSM));
}

llvm::Expected<llvm::orc::ExecutorSymbolDef> llvm::orc::KaleidoscopeJIT::lookup(llvm::StringRef Name) {
    return ES->lookup({&MainJD}, Mangle(Name.str()));
}