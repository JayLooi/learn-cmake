cmake_minimum_required(VERSION 3.16)

project(
    helloCMakeWorld
    VERSION 0.1
    LANGUAGES CXX
)

configure_file(config.h.in config.h)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(helloCMakeWorld main.cpp)