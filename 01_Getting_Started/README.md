# Getting Started with CMake

This is my **`"Hello World"`** equivalent in CMake. 

The CMake commands used here:
1. [`cmake_minimum_required`](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html)
   - set the minimum required CMake version for the project. 
2. [`project`](https://cmake.org/cmake/help/latest/command/project.html)
   - set the project name, and optionally set version, description, homepage url as well as programming languages. 
3. [`configure_file`](https://cmake.org/cmake/help/latest/command/configure_file.html)
   - copies input file in first argument to output file in second argument, and replaces `@VAR@` or `${VAR}` with the actual variable value. 
4. [`include_directories`](https://cmake.org/cmake/help/latest/command/include_directories.html)
   - adds directories for compiler to use for searching include files. 
5. [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html)
   - adds an executable target with name specified in first argument, which to be built from the list of source files specified in following arguments. 

## Prerequisites

- C++ compiler (I use GNU g++ on Ubuntu 20.04)
- GNU Make

On Ubuntu machine, both of these tools can be installed with:

```
sudo apt install build-essential
```

On Windows, the equivalent GCC tools can be installed by installing MinGW/MinGW-w64, or you can choose your preferred compiler and build system tool. 

## Getting started

### Run CMake

In the `01_Getting_Started/` dir: 

```
mkdir build
cd build
cmake ..
```

### Compile

```
make
```

### Execute compiled program

```
./helloCMakeWorld arg1 arg2 abc 123
```