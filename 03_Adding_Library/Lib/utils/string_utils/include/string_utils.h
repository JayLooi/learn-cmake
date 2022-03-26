/**
 * @file string_utils.h
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief Useful string utility functions. 
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/********** Internal Includes **********/


/********** External Includes **********/


/********** Standard Includes **********/
#include <string>
#include <vector>


#define STRINGIFY_HELPER(STR)    #STR
#define STRINGIFY(STR)      STRINGIFY_HELPER(STR)

std::vector<std::string> str_split(const std::string& str, char delim);

#endif  // STRING_UTILS_H