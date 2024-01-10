//
// Created by Chuck Zumbaugh on 1/8/24.
//

#ifndef KALIEDOSCOPE_KALIEDOSCOPEJIT_H
#define KALIEDOSCOPE_KALIEDOSCOPEJIT_H

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
#include <memory>

namespace llvm {
    namespace orc {

        class KaleidoscopeJIT {
        private:
            std::unique_ptr<ExecutionSession> ES;

            DataLayout DL;
            MangleAndInterner Mangle;

            RTDyldObjectLinkingLayer ObjectLayer;
            IRCompileLayer CompileLayer;

            JITDylib &MainJD;

        public:
            KaleidoscopeJIT(std::unique_ptr<ExecutionSession> ES,
                            JITTargetMachineBuilder JTMB, DataLayout DL);

            ~KaleidoscopeJIT();

            static Expected<std::unique_ptr<KaleidoscopeJIT>> Create();

            const DataLayout &getDataLayout() const { return DL; }

            JITDylib &getMainJITDylib() { return MainJD; }

            Error addModule(ThreadSafeModule TSM, ResourceTrackerSP RT = nullptr);

            Expected<ExecutorSymbolDef> lookup(StringRef Name);
        };

    } // end namespace orc
} // end namespace llvm

#endif //KALIEDOSCOPE_KALIEDOSCOPEJIT_H
