# This cmake script demonstrated control flow functionalities in CMake

math(EXPR last_arg_index ${CMAKE_ARGC}-1)

# Search for running script name by looping over argument(s) from command line
foreach(n RANGE ${last_arg_index})
    if(CMAKE_ARGV${n} STREQUAL -P)
        math(EXPR _n ${n}+1)
        message(STATUS "Running ${CMAKE_ARGV${_n}}")
        break()
    endif()
endforeach()

# Check for type of C/Cpp file
if(DEFINED filename)
    if(filename MATCHES "[.](c|cpp|cc)$")
        message(STATUS "Source file detected")
    elseif(filename MATCHES "[.](h|hpp)$")
        message(STATUS "Header file detected")
    else()
        message(STATUS "Not C/Cpp file")
    endif()
else()
    message(STATUS "No input file")
endif()
