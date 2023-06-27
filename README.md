# Writing an LLVM Pass
This repository contains a simple example of creating an LLVM pass. LLVM (Low-Level Virtual Machine) is a collection of modular and reusable compiler and toolchain technologies. 

## Downloading LLVM on MacOS
1. Install Homebrew
```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```
2. Install LLVM
```brew install llvm```
3. Follow the instructions as shown on your terminal
4. Add llvm to path in .bash_profile by adding below line
```export PATH="/opt/homebrew/opt/llvm/bin:$PATH"```
   - Note : Replace the LLVM path with yours if it is different.
6. Run ```source ~/.bash_profile``` to apply the changes
7. Now you can check versions of llvm, clang and clag++ by running ```llvm-config --version```, ```clang --version``` and ```clang++ --version``` respectively
8. Download [this]([https://www.google.com/](https://github.com/llvm/llvm-project))repository on your system and unzip it

## Building the Hello World Pass (Similar for all Operating System)
- Navigate to the project directory in uzipped foder named llvm ```cd llvm```
- Create a build directory and navigate into it ```mkdir build
   cd build```
- Generate the build files using CMake ```cmake ..```
- Note : You may encouter an error here ```No build type selected. You need to pass -DCMAKE_BUILD_TYPE=<type> in order to configure LLVM.``` In this case pass ```-DCMAKE_BUILD_TYPE=Debug``` .
- Build the project ```cmake --build .```
  - It may take some time, so you can enjoy a cup of coffee while waiting :)
- Now come back to your project directory ```cd ..```
- Navigate to ```cd lib/Transforms/```
- Add the following into lib/Transforms/CMakeLists.txt
  ```
  add_subdirectory(your_pass_name)
  ```
- Make a new directory for your pass and navigate to it ```mkdir your_pass``` and ```cd your_pass```
- ```vim CMakeLists.txt``` and add the following lines
```
add_llvm_library( LLVMYourPass MODULE
  YourPass.cpp

  PLUGIN_TOOL
  opt
  )
```
Replace ```YourPass``` with ```your_own_pass_name```
- Make a .cpp file named ```YourPass.cpp``` and add the code from the provided .cpp file in this repository.
- Navigate to build ```cd ../../../build/``` and Build the updates using previous commands ```cmake ..``` and ```cmake --build .```
- This will register your new pass with LLVM

## Running the Hello World Pass
- Compile the source file into LLVM bitcode using Clang
```
clang -emit-llvm -c path/to/source.c
```
You may specify output file path as well ```-o path/to/output.bc```. For simplicity, I suggest keeping the source file in the build directory.  
You can use a most basic C file for your input, like :

```
#include <stdio.h>
int main(){
   printf("Hello, World!\n");
   return 0;
}  
```
- Run YourPass on the generated LLVM bitcode
```
./bin/opt -load path/to/HelloWorldPass.so -your_pass_name < path/to/output.bc > /dev/null
```
Replace the paths with your own.  
**Imp: For version greater than 12 add ```-enable-new-pm=0``` in above command.**  
- This will print ``` Your pass output : function_name_in_input_file(main)``` in the terminal.

## Understanding the Hello World Pass
- This is a very simple LLVM pass that inserts a "Your pass output" string into the entry block of each function in the input code. You can find the pass implementation in the YourPass.cpp file.

- Feel free to modify the pass to perform different transformations or analysis tasks according to your requirements.

## References
- [LLVM Project](https://llvm.org/)
- [Writing LLVM Pass](https://www.llvm.org/docs/WritingAnLLVMPass.html#introduction-what-is-a-pass)
- [LLVM GitHub Repository](https://github.com/llvm/llvm-project)

  Enjoy exploring the LLVM Pass! If you have any questions, feel free to reach out.
