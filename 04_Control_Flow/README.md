# CMake Control Flow

Essentially, CMake is an interpreted scripting language. Just like other languages, CMake comes with control flow syntax to help in structuring the flow of the script. 

In this section, a minimal CMake script is created to demonstrate the usage of [`if`](https://cmake.org/cmake/help/latest/command/if.html) and [`foreach`](https://cmake.org/cmake/help/latest/command/foreach.html) in the script control flow. 

## Demo

```bash
$ cmake -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- No input file

$ cmake -Dfilename=abc.c -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Source file detected

$ cmake -Dfilename=abc.cpp -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Source file detected

$ cmake -Dfilename=abc.cc -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Source file detected

$ cmake -Dfilename=abc.h -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Header file detected

$ cmake -Dfilename=abc.hpp -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Header file detected

$ cmake -Dfilename=abc.java -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Not C/Cpp file

$ cmake -Dfilename=abc.pyc -P ControlFlow_Demo.cmake
# Output:
# -- Running ControlFlow_Demo.cmake
# -- Not C/Cpp file
```
