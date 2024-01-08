//
// Created by Chuck Zumbaugh on 1/8/24.
//

#ifndef KALIEDOSCOPE_KALIEDOSCOPEJIT_H
#define KALIEDOSCOPE_KALIEDOSCOPEJIT_H

#include <memory>
#include "llvm/ADT/StringRef.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/ExecutorProcessControl.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/Orc/Shared/ExecutorSymbolDef.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"


class KaliedoscopeJIT {
private:
    std::unique_ptr<llvm::orc::ExecutionSession> ES;
    llvm::DataLayout DL;
    llvm::orc::MangleAndInterner mangle;
    llvm::orc::RTDyldObjectLinkingLayer objectLayer;
    llvm::orc::IRCompileLayer compileLayer;
    llvm::orc::JITDylib &mainJD;

public:
    KaliedoscopeJIT(std::unique_ptr<llvm::orc::ExecutionSession> ES, llvm::orc::JITTargetMachineBuilder JTMB,
                    llvm::DataLayout dataLayout): ES(std::move(ES)), DL(std::move(DL)), mangle(*this->ES, this->DL),
                                                  objectLayer(*this->ES, []() {
                                                      return std::make_unique<llvm::SectionMemoryManager>();
                                                  }),
                                                  compileLayer(*this->ES, objectLayer,
                                                               std::make_unique<llvm::orc::ConcurrentIRCompiler>(std::move(JTMB))),
                                                               mainJD(this->ES->createBareJITDylib("<main>")) {
        mainJD.addGenerator(llvm::cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(
                DL.getGlobalPrefix()
                )));
        if (JTMB.getTargetTriple().isOSBinFormatCOFF()) {
            objectLayer.setOverrideObjectFlagsWithResponsibilityFlags(true);
            objectLayer.setAutoClaimResponsibilityForObjectSymbols(true);
        }
    }

    ~KaliedoscopeJIT();

    static llvm::Expected<std::unique_ptr<KaliedoscopeJIT>> create();
    const llvm::DataLayout& getDataLayout();
    llvm::orc::JITDylib& getMainJITDylib();
    llvm::Error addModule(llvm::orc::ThreadSafeModule TSM, llvm::orc::ResourceTrackerSP RT = nullptr);
}
;


#endif //KALIEDOSCOPE_KALIEDOSCOPEJIT_H
