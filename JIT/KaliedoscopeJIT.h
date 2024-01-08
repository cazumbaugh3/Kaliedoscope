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
};


#endif //KALIEDOSCOPE_KALIEDOSCOPEJIT_H
