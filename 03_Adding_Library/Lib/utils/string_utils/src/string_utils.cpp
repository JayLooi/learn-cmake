/**
 * @file string_utils.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/********** Internal Includes **********/
#include "string_utils.h"


/********** External Includes **********/


/********** Standard Includes **********/
#include <sstream>

std::vector<std::string> str_split(const std::string& str, char delim)
{
    std::vector<std::string> split_str_vector;
    std::stringstream ss(str);
    for (std::string elem; std::getline(ss, elem, delim); )
    {
        split_str_vector.push_back(elem);
    }

    return split_str_vector;
}