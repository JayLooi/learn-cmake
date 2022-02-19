/**
 * @file main.cpp
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief Simple cpp program to getting started with CMake. 
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "config.h"

int main (int argc, char *argv[])
{
    std::cout << argv[0] << std::endl;
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    std::cout << "Hello, World! " << std::endl;
    
    if (argc > 1)
    {
        std::cout << "List of args:" << std::endl;
    
        for (int i = 1; i < argc; i++)
        {
            std::cout << i << ") " << argv[i] << std::endl;
        }
    }

    return 0;
}