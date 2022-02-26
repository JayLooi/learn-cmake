/**
 * @file app.cpp
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief Simple app to draw a table in terminal. 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/********** Internal Includes **********/
// #include "Logging.h"
#include "simple_argparse.h"
#include "string_utils.h"
#include "Table.h"


/********** External Includes **********/


/********** Standard Includes **********/
#include <exception>
#include <iostream>


int main(int argc, char *argv[])
{
    simple_argparse::ArgumentParser parser(argv[0]);
    parser.add_argument("nrow", simple_argparse::argument_type::argtype_int);
    parser.add_argument("ncol", simple_argparse::argument_type::argtype_int);
    parser.add_argument("--entries", simple_argparse::argument_type::argtype_str);
    std::map<std::string, simple_argparse::Argument> args;
    
    try
    {
        args = parser.parse_args(argc - 1, argv + 1);
    }
    catch(const std::invalid_argument& e)
    {
        return 1;
    }
    
    std::vector<std::vector<std::string>> entries;

    if (args["entries"].get<std::string>().length() > 0)
    {
        for (auto row : str_split(args["entries"].get<std::string>(), ';'))
        {
            entries.push_back(str_split(row, ','));
        }
    }

    Table::Table table((unsigned int)args["nrow"].get<int>(), (unsigned int)args["ncol"].get<int>(), entries, "##EMPTY_CELL##");
    table.display();

    return 0;
}