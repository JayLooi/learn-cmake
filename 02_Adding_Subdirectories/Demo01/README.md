# Demo01

In this Demo, only a single top-level `CMakeLists.txt` is used to manage the build. 

All the include paths are specified in the command `include_directories`, so that the compiler can search for the `#include` header files in these paths.

All the required source files are specified in the command `add_executable` so that the source files can be compiled into the target. 

Since this demo project is small so this approach works fine. 

## Build and Run

### Run CMake

In the `02_Adding_Subdirectories/Demo01/` dir: 

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
./cmakeSubDirDemo01 5 3 --entries "A,B,A XOR B;0,0,0;0,1,1;1,0,1;1,1,0"
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
