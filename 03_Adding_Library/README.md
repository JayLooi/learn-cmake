# Adding Libraries

As mentioned in [02_Adding_Subdirectories](https://github.com/JayLooi/learn-cmake/tree/master/02_Adding_Subdirectories), splitting a large project into multiple modules (subdirectories) can improve maintainability. 

Often, in an organisation, there will be more than one project to be developed. So, it is beneficial if those modules can be reused/ported in different projects. 

However, the CMake strategies used in [02_Adding_Subdirectories](https://github.com/JayLooi/learn-cmake/tree/master/02_Adding_Subdirectories) couldn't help in the modules reusability because the module-level **CMakeLists.txt** would need to be modified or even rewritten to adapt the differences in another project. 

In order to reduce the effort of reusing/porting the modules in another project, each module is treated as a library with the help of CMake command `add_library`. 

<u> **The Demo project structure**: </u>
```
├── Lib
│   ├── table
│   │   ├── include
│   │   │   └── Table.h
│   │   ├── src
│   │   │   └── Table.cpp
│   │   └── CMakeLists.txt
│   ├── utils
│   │   ├── simple_argparse
│   │   │   ├── include
│   │   │   │   └── simple_argparse.h
│   │   │   ├── src
│   │   │   │   └── simple_argparse.cpp
│   │   │   └── CMakeLists.txt
│   │   ├── string_utils
│   │   │   ├── include
│   │   │   │   └── string_utils.h
│   │   │   ├── src
│   │   │   │   └── string_utils.cpp
│   │   │   └── CMakeLists.txt
│   │   └── CMakeLists.txt
│   └── CMakeLists.txt
├── app.cpp
└── CMakeLists.txt
```

In each module, `add_library(libname STATIC)` is invoked to create a library target. The required sources and include directories are added to the target by `target_sources` and `target_include_directories` commands. 

The difference between the module-level **CMakeLists.txt** here from the one in [02_Adding_Subdirectories/Demo03](https://github.com/JayLooi/learn-cmake/tree/master/02_Adding_Subdirectories/Demo03) is that each module in **Lib/** here is a standalone library which can be built independently. 

## Build and Run

### Run CMake

In the `03_Adding_Library/` dir: 

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
./drawTable 5 3 --entries "A,B,A XOR B;0,0,0;0,1,1;1,0,1;1,1,0"
```
### Output
```
+-+-+-------+
|A|B|A XOR B|
+-+-+-------+
|0|0|0      |
+-+-+-------+
|0|1|1      |
+-+-+-------+
|1|0|1      |
+-+-+-------+
|1|1|0      |
+-+-+-------+
```

## Build library target only

In the `03_Adding_Library/build/` dir: 

```
rm -r *
cmake ../Lib
make <Lib-name>
```
