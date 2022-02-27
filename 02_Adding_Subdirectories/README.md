# Adding More Files and Subdirectories

In [01_Getting_Started](https://github.com/JayLooi/learn-cmake/tree/master/01_Getting_Started), there is only one `CMakeLists.txt` in the project root directory. Using a single `CMakeLists.txt` to manage a project build system is only suitable if the project is small with few files and subdirectories. 

As the project grows, the single `CMakeLists.txt` in root directory would become too long and thus reducing the readability and maintainability. So, it is better to organise the files into different subdirectories as well as split the top-level `CMakeLists.txt` into smaller maintainable files for each subdirectory. 

There are two main CMake commands to handle the multi-directory project:
1. [`include`](https://cmake.org/cmake/help/latest/command/include.html)
2. [`add_subdirectory`](https://cmake.org/cmake/help/latest/command/add_subdirectory.html)

In this part, there will be 3 demo for different methods to handle multi-directory project:
1. Demo01
   - Single CMakeLists.txt in project root (not suitable if project is very big)
2. Demo02
   - Use `include` command to traverse through all CMakeLists.txt in each subdirectory
3. Demo03
   - Use `add_subdirectory` command to traverse through all CMakeLists.txt in each subdirectory

<u> **The Demo project structure**: </u>
```
├── pkg
│   ├── table
│   │   ├── include
│   │   │   └── Table.h
│   │   └── src
│   │       └── Table.cpp
│   └── utils
│       ├── simple_argparse
│       │   ├── include
│       │   │   └── simple_argparse.h
│       │   └── src
│       │       └── simple_argparse.cpp
│       └── string_utils
│           ├── include
│           │   └── string_utils.h
│           └── src
│               └── string_utils.cpp
└── app.cpp
```
