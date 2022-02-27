# Demo03

In this Demo, there are **CMakeLists.txt** in each of the directories:
- Demo03/
- Demo03/pkg/table
- Demo03/pkg/utils
- Demo03/pkg/utils/simple_argparse
- Demo03/pkg/utils/string_utils

In the **CMakeLists.txt** of **pkg/table**, **pkg/utils/simple_argparse** and **pkg/utils/string_utils**, the source files and include paths are added directly to the top-level target (executable). 

```
target_sources(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        src/xxx.cpp
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        "include"
)
```

The upper-level **CMakeLists.txt** invokes the command `add_subdirectory` with the directory down in the hierarchy of project which contains another **CMakeLists.txt**. Upon the invocation of `add_subdirectory`, the **CMakeLists.txt** in the specified directory is processed immediately by CMake. 

In top-level **CMakeLists.txt**, `add_executable` is called with the source files list on the same level. Then, `add_subdirectory(pkg)` is called to process all the **CMakeLists.txt** files down in the hierarchy, which will eventually add the required source files and include paths to the target. 

## Build and Run

### Run CMake

In the `02_Adding_Subdirectories/Demo03/` dir: 

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
./cmakeSubDirDemo03 5 3 --entries "A,B,A XOR B;0,0,0;0,1,1;1,0,1;1,1,0"
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
