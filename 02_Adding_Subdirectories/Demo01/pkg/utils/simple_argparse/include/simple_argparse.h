/**
 * @file simple_argparse.h
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief A simple module for parsing command line arguments. 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SIMPLE_ARGPARSE_H
#define SIMPLE_ARGPARSE_H

/********** Internal Includes **********/


/********** External Includes **********/


/********** Standard Includes **********/
#include <map>
#include <string>
#include <vector>


namespace simple_argparse
{
    enum argument_type
    {
        argtype_bool,
        argtype_int,
        argtype_double, 
        argtype_str,
        argtype_total
    };

    union GenericArgument
    {
        GenericArgument()
        {
            new (&arg_str) std::string;
        }
        ~GenericArgument() {}
        bool arg_bool;
        int arg_int;
        double arg_double;
        std::string arg_str;
    };

    class Argument
    {
    public:
        Argument() = default;
        Argument(const Argument& argument);
        Argument(std::string raw_arg_str, argument_type arg_type);
        Argument(argument_type arg_type);
        template <class T> T get();
        void set(std::string raw_str);
        inline argument_type get_type() { return arg_type; }

    private:
        argument_type arg_type;
        GenericArgument arg;
    };

    class ArgumentParser
    {
    public:
        ArgumentParser(std::string prog_name="", std::string description="");
        Argument& add_argument(std::string arg_name, argument_type arg_type, bool required=false);
        std::map<std::string, Argument>& parse_args(int argc, char *argv[]);
        Argument& operator[](std::string key);
        std::string get_help();

    private:
        bool check_argument_name(std::string arg_name, std::string &new_arg_name);
        std::string prog_name;
        std::string description;
        std::vector<std::string> help;
        std::vector<std::string> positional_args;
        std::map<std::string, bool> args_required;
        std::map<std::string, std::string> optional_arg_name_map;
        std::map<std::string, Argument> arg_list;
    };
} // namespace simple_argparse

#endif  // SIMPLE_ARGPARSE_H