// This file implements a basic LLVM Pass
// By Rishabh Kumar : RishabhS21

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;

namespace {
struct YourPass : public FunctionPass {
  static char ID;
  YourPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    errs() << "Your Pass Output: ";
    errs().write_escaped(F.getName()) << '\n';
    return false;
  }
}; // end of struct YourPass
}  // end of anonymous namespace

char YourPass::ID = 0;
static RegisterPass<YourPass> X("your_pass_name", "Your Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);

// Feel free to modify the pass to perform different transformations or analysis tasks according to your requirements.
