# Getting Started with CMake

This is the **`"Hello World"`** level of CMake. 

The CMake commands used here:
- `cmake_minimum_required()`
- `project()`
- `configure_files()`
- `include_directories()`
- `add_executable()`

## Prerequisites

- C++ compiler (I use GNU g++ on Ubuntu 20.04)
- GNU Make

On Ubuntu machine, both of these tools can be installed with:

```
sudo apt install build-essentials
```

On Windows, the equivalent tools can be installed with MinGW, or you can choose your preferred compiler and build system tool. 

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