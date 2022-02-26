/**
 * @file Table.cpp
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief A class to create simple 2D table. 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/********** Internal Includes **********/
#include "Table.h"


/********** External Includes **********/


/********** Standard Includes **********/
#include <iostream>


namespace Table
{
    Table::Table(unsigned int num_of_row, unsigned int num_of_col, const std::vector<std::vector<std::string>> &entries, std::string empty_fill)
        :num_of_row(num_of_row), num_of_col(num_of_col)
    {
        this->entries = entries;
        auto entries_rows = this->entries.size();

        for (unsigned int i = 0; i < num_of_row; ++i)
        {
            if (i < entries_rows)
            {
                auto entries_cols = this->entries[i].size(); 
                for (unsigned int j = entries_cols; j < num_of_col; ++j)
                {
                    this->entries[i].push_back(empty_fill);
                }
            }
            else
            {
                this->entries.push_back(std::vector<std::string>());
                for (unsigned int j = 0; j < num_of_col; ++j)
                {
                    this->entries[i].push_back(empty_fill);
                }
            }
        }

        for (unsigned int i = 0; i < num_of_col; ++i)
        {
            unsigned int width = 0;
            for (unsigned int j = 0; j < num_of_row; ++j)
            {
                if (this->entries[j][i].length() > width)
                {
                    width = this->entries[j][i].length();
                }
            }

            col_width.push_back(width);
        }
    }

    void Table::display()
    {
        std::string horizontal_border = "+";
        for (auto n : col_width)
        {
            horizontal_border.insert(horizontal_border.length(), n, '-');
            horizontal_border.push_back('+');
        }

        std::cout << horizontal_border << std::endl;

        std::string entry;
        unsigned int len;
        for (unsigned int i = 0; i < num_of_row; ++i)
        {
            std::cout << "|";
            auto row = this->entries[i];
            for (unsigned int j = 0; j < num_of_col; ++j)
            {
                entry = row[j];
                len = entry.length();
                if (len < col_width[j])
                {
                    entry.insert(len, col_width[j] - len, ' ');
                }
                std::cout << entry << "|";
            }
            std::cout << std::endl << horizontal_border << std::endl;
        }
    }
} // namespace Table
