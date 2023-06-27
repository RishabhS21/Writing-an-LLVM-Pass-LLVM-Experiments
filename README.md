# Writing-an-LLVM-Pass-LLVM-Experiments
This repository contains a simple example of creating an LLVM pass. LLVM (Low-Level Virtual Machine) is a collection of modular and reusable compiler and toolchain technologies. 

## Downloading LLVM on MacOS
1. Install Homebrew
```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```
2. Install LLVM
```brew install llvm```
3. Follow the instructions as shown on your terminal
4. Add llvm to path in .bash_profile by adding below line
```export PATH="/opt/homebrew/opt/llvm/bin:$PATH"```
Note : Replace llvm path as yours if different.
