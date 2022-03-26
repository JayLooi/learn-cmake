cmake_minimum_required(VERSION 3.16)

project(
    drawTable
    VERSION 0.1
    LANGUAGES CXX
)

add_subdirectory(Lib)

add_executable(
    ${PROJECT_NAME}
    app.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Table simple_argparse string_utils)
