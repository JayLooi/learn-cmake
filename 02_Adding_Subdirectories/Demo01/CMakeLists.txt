cmake_minimum_required(VERSION 3.16)

project(
    cmakeSubDirDemo01
    VERSION 0.1
    LANGUAGES CXX
)

include_directories(
    pkg/table/include
    pkg/utils/simple_argparse/include
    pkg/utils/string_utils/include
)

add_executable(
    ${PROJECT_NAME}
    app.cpp
    pkg/table/src/Table.cpp
    pkg/utils/simple_argparse/src/simple_argparse.cpp
    pkg/utils/string_utils/src/string_utils.cpp
)