/**
 * @file simple_argparse.cpp
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief A simple module for parsing command line arguments. 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/********** Internal Includes **********/
#include "simple_argparse.h"
#include "string_utils.h"


/********** External Includes **********/


/********** Standard Includes **********/
#include <algorithm>
#include <exception>
#include <iostream>
#include <regex>
#include <sstream>


#define current_file_and_line   __FILE__ ":" STRINGIFY(__LINE__)

#define throw_invalid_template_param(param, arg_type)    \    
    throw std::logic_error( std::string("Exception thrown at ") + current_file_and_line + \
                            "\nInvalid template parameter '" + param + \
                            "' for method 'T get()' in the instance of 'Argument' class with member 'arg_type' NOT equal to '" + \
                            arg_type + "'. \n")

#define throw_invalid_argument(msg)     \
    throw std::invalid_argument(std::string("Exception thrown at ") + current_file_and_line + "\n" + msg + '\n')

namespace simple_argparse
{
    Argument::Argument(std::string raw_arg_str, argument_type arg_type)
        : Argument(arg_type)
    {
        set(raw_arg_str);
    }

    Argument::Argument(argument_type arg_type)
        : arg_type(arg_type)
    {
        
    }

    Argument::Argument(const Argument& argument)
    {
        this->arg_type = argument.arg_type;
        switch (this->arg_type)
        {
            case argtype_bool:
                arg.arg_bool = argument.arg.arg_bool;
                break;
            
            case argtype_int:
                arg.arg_int = argument.arg.arg_int;
                break;
                
            case argtype_double:
                arg.arg_double = argument.arg.arg_double;
                break;
                
            case argtype_str:
                new (&arg.arg_str) std::string(argument.arg.arg_str);
                break;
                
            default:
                break;
        }
    }

    template <> bool Argument::get()
    {
        if (arg_type == argtype_bool)
        {
            return arg.arg_bool; 
        }
        else
        {
            throw_invalid_template_param("bool", "argtype_bool");
        }
    }

    template <> int Argument::get()
    {
        if (arg_type == argtype_int)
        {
            return arg.arg_int; 
        }
        else
        {
            throw_invalid_template_param("int", "argtype_int");
        }
    }

    template <> double Argument::get()
    {
        if (arg_type == argtype_double)
        {
            return arg.arg_double; 
        }
        else
        {
            throw_invalid_template_param("double", "argtype_double");
        }
    }

    template <> std::string Argument::get()
    {
        if (arg_type == argtype_str)
        {
            return arg.arg_str; 
        }
        else
        {
            throw_invalid_template_param("std::string", "argtype_str");
        }
    }

    void Argument::set(std::string raw_str)
    {
        switch (this->arg_type)
        {
            case argtype_bool:
                arg.arg_bool = (std::stoi(raw_str) > 0);
                break;
            
            case argtype_int:
                arg.arg_int = std::stoi(raw_str);
                break;
                
            case argtype_double:
                arg.arg_double = std::stof(raw_str);
                break;
                
            case argtype_str:
                new (&arg.arg_str) std::string(raw_str);
                break;
                
            default:
                break;
        }
    }

    ArgumentParser::ArgumentParser(std::string prog_name, std::string description)
        : prog_name(prog_name), description(description)
    {
        std::regex replace_regex(".*[/\\\\]");
        this->prog_name = std::regex_replace(prog_name, replace_regex, "");
        help.push_back("usage: " + this->prog_name);
        help.push_back("");     // For positional argument(s)
        help.push_back("");     // For opitonal argument(s)
        add_argument("--help", simple_argparse::argument_type::argtype_bool);
    }

    bool ArgumentParser::check_argument_name(std::string arg_name, std::string &new_arg_name)
    {
        std::regex word_regex("^-{0,2}[A-Za-z]+[-A-Za-z0-9]*");

        if (std::regex_search(arg_name, word_regex))
        {
            std::regex replace_regex("^-{0,2}");
            new_arg_name = std::regex_replace(arg_name, replace_regex, "");
            std::replace(new_arg_name.begin(), new_arg_name.end(), '-', '_');

            return true;
        }

        return false;
    }

    Argument& ArgumentParser::add_argument(std::string arg_name, argument_type arg_type, bool required)
    {
        std::string new_arg_name;

        if (check_argument_name(arg_name, new_arg_name))
        {
            if (arg_name.at(0) != '-')
            {
                positional_args.push_back(new_arg_name);
                help[1] += "<" + new_arg_name + "> ";
            }
            else
            {
                args_required.emplace(new_arg_name, required);
                optional_arg_name_map.emplace(new_arg_name, arg_name);

                std::string arg_usage = arg_name;
                if (arg_type != argtype_bool)
                {
                    arg_usage += " <" + new_arg_name + ">";
                }

                if (!required)
                {
                    arg_usage.insert(0, "[");
                    arg_usage.insert(arg_usage.length(), "]");
                }

                help[2] += arg_usage + " ";
            }

            arg_list.emplace(new_arg_name, Argument(arg_type));
            return arg_list[new_arg_name];
        }
        else
        {
            throw_invalid_argument("Invalid 'arg_name' string format in the first argument of 'ArgumentParser::add_argument'.");
        }
    }

    std::map<std::string, Argument>& ArgumentParser::parse_args(int argc, char *argv[])
    {
        std::string key;
        auto num_of_positional_arg = positional_args.size();
        unsigned i = 0;
        std::map<std::string, bool> required_args_check = args_required;
        
        for (auto &elem : required_args_check)
        {
            elem.second = false;
        }

        for (i = 0; i < argc; ++i)
        {
            if (std::strcmp(argv[i], "--help") == 0)
            {
                std::cout << get_help() << std::endl;
                std::exit(0);
            }
        }

        try
        {
            if (argc < num_of_positional_arg)
            {
                throw_invalid_argument( "Program: " + prog_name + " expects " + std::to_string(num_of_positional_arg) + 
                                        " positional argument(s) but actual only " + std::to_string(argc) + " given. ");
            }

            for (i = 0; i < num_of_positional_arg; ++i)
            {
                arg_list[positional_args[i]].set(argv[i]);
            }

            for (; i < argc; ++i)
            {
                if (check_argument_name(argv[i], key))
                {
                    if (arg_list.find(key) != arg_list.end())
                    {
                        if (args_required[key] && ((arg_list[key].get_type() == argtype_bool) || ((i + 1) < argc)))
                        {
                            required_args_check[key] = true;
                        }

                        if (arg_list[key].get_type() == argtype_bool)
                        {
                            arg_list[key].set("1");
                        }
                        else if ((i + 1) < argc)
                        {
                            ++i;
                            arg_list[key].set(argv[i]);
                        }
                    }
                    else
                    {
                        throw_invalid_argument("Unknown option: " + argv[i]);
                    }
                }
                else
                {
                    throw_invalid_argument("Unknown option: " + argv[i]);
                }
            }

            if (required_args_check != args_required)
            {
                std::string missing_required_args;
                for (auto &elem : args_required)
                {
                    if (elem.second != required_args_check[elem.first])
                    {
                        missing_required_args += "[" + optional_arg_name_map[elem.first] + "]\n";
                    }
                }

                throw_invalid_argument("Program: " + prog_name + " missing required input optional argument(s) : \n" + 
                                        missing_required_args);
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl << get_help();
            throw;
        }

        return arg_list;
    }

    Argument& ArgumentParser::operator[](std::string key)
    {
        if (arg_list.find(key) != arg_list.end())
        {
            return arg_list[key];
        }
        else
        {
            throw_invalid_argument("'arg_list' which is a member of the instance of 'ArgumentParser', does not 'key' of value '" + key + "'");
        }
    }

    std::string ArgumentParser::get_help()
    {
        std::stringstream ss;
        ss << help[0] << " " << help[1] << " " << help[2] << std::endl;
        return ss.str();
    }
} // namespace simple_argparses