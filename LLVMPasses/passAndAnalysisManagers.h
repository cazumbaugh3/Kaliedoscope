//
// Created by Chuck Zumbaugh on 1/9/24.
//

#ifndef KALIEDOSCOPE_PASSANDANALYSISMANAGERS_H
#define KALIEDOSCOPE_PASSANDANALYSISMANAGERS_H
#include <memory>
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/StandardInstrumentations.h"


extern std::unique_ptr<llvm::FunctionPassManager>  theFPM;
extern std::unique_ptr<llvm::LoopAnalysisManager> theLAM;
extern std::unique_ptr<llvm::FunctionAnalysisManager> theFAM;
extern std::unique_ptr<llvm::CGSCCAnalysisManager> theCGAM;
extern std::unique_ptr<llvm::ModuleAnalysisManager> theMAM;
extern std::unique_ptr<llvm::PassInstrumentationCallbacks> thePIC;
extern std::unique_ptr<llvm::StandardInstrumentations> theSI;

#endif //KALIEDOSCOPE_PASSANDANALYSISMANAGERS_H
