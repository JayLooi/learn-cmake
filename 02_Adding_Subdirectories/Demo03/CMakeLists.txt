cmake_minimum_required(VERSION 3.16)

project(
    cmakeSubDirDemo03
    VERSION 0.1
    LANGUAGES CXX
)

add_executable(
    ${PROJECT_NAME}
    app.cpp
)

add_subdirectory(pkg)
