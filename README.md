# Writing-an-LLVM-Pass-LLVM-Experiments
This repository contains a simple example of creating an LLVM pass. LLVM (Low-Level Virtual Machine) is a collection of modular and reusable compiler and toolchain technologies. 

## Downloading LLVM on MacOS
1. Install Homebrew
```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```
2. Install LLVM
```brew install llvm```
3. Follow the instructions as shown on your terminal
4. Add llvm to path in .bash_profile by adding below line
```export PATH="/opt/homebrew/opt/llvm/bin:$PATH"``` \n
Note : Replace llvm path as yours if different.
5. Run ```source ~/.bash_profile``` to apply the changes
6. Now you can check versions of llvm, clang and clag++ by running ```llvm-config --version```, ```clang --version``` and ```clang++ --version``` respectively
7. Download [this]([https://www.google.com/](https://github.com/llvm/llvm-project))repository on your system and unzip it

## Building the Hello World Pass (Similar for all Operating System)
1. Navigate to the project directory in uzipped foder named llvm ```cd llvm```
2. Create a build directory and navigate into it ```mkdir build
   cd build```
3. Generate the build files using CMake ```cmake ..```
\n Note : You may encouter an error here ```No build type selected. You need to pass -DCMAKE_BUILD_TYPE=<type> in order to configure LLVM.``` In this case pass ```-DCMAKE_BUILD_TYPE=Debug``` .
4. Build the project ```cmake --build .``` It may take a longer time have a cup of coffee till then.
5. Now come back to your project directory ```cd ..```
6. Navigate to ```cd lib/Transforms/```
7. Add the following into lib/Transforms/CMakeLists.txt \n
```add_subdirectory(your_pass_name)```
8. Make a new directory for your pass and navigate to it ```mkdir your_pass
   cd your_pass```
9. ```vim CMakeLists.txt``` and add following lines
```
add_llvm_library( LLVMYourPass MODULE
  YourPass.cpp

  PLUGIN_TOOL
  opt
  )
```
Replace ```YourPass``` with ```your_own_pass_name```
10. Make a cpp file named ```YourPass.cpp``` and add code of above given cpp file there
11. Navigate to build ```cd ../../../build/``` and Build the updates using previous command ```cmake ..``` and ```cmake --build .```
12. This will register your new pass with llvm
