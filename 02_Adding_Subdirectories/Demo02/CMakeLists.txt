cmake_minimum_required(VERSION 3.16)

project(
    cmakeSubDirDemo02
    VERSION 0.1
    LANGUAGES CXX
)

include(pkg/CMakeLists.txt)

include_directories(${INCLUDE_DIRS_LIST})

add_executable(
    ${PROJECT_NAME}
    app.cpp
    ${SOURCE_FILES_LIST}
)
