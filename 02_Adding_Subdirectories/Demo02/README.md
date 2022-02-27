# Demo02

In this Demo, there are **CMakeLists.txt** in each of the directories:
- Demo02/
- Demo02/pkg/table
- Demo02/pkg/utils
- Demo02/pkg/utils/simple_argparse
- Demo02/pkg/utils/string_utils

The source files list and include paths list are built up in the **CMakeLists.txt** of **pkg/table**, **pkg/utils/simple_argparse** and **pkg/utils/string_utils**, and stored in `SOURCE_FILES_LIST` and `INCLUDE_DIRS_LIST` respectively. 

```
list(
    APPEND SOURCE_FILES_LIST
    ${CMAKE_CURRENT_LIST_DIR}/src/xxx.cpp
)

list(
    APPEND INCLUDE_DIRS_LIST
    "${CMAKE_CURRENT_LIST_DIR}/include"
)
```

The upper-level **CMakeLists.txt** invokes the command `include` with the path of another **CMakeLists.txt** down in the hierarchy of project to bring the variable `SOURCE_FILES_LIST` and `INCLUDE_DIRS_LIST` to top-level. 

In top-level **CMakeLists.txt**, both the variables are used in `include_directories` and `add_executable` commands.  
```
include_directories(${INCLUDE_DIRS_LIST})

add_executable(
    ${PROJECT_NAME}
    app.cpp
    ${SOURCE_FILES_LIST}
)
```

## Build and Run

### Run CMake

In the `02_Adding_Subdirectories/Demo02/` dir: 

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
./cmakeSubDirDemo02 5 3 --entries "A,B,A XOR B;0,0,0;0,1,1;1,0,1;1,1,0"
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
