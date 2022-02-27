/**
 * @file Table.h
 * @author Looi Kian Seong (kianseong.looi@gmail.com)
 * @brief A class to create simple 2D table. 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TABLE_H
#define TABLE_H
/********** Internal Includes **********/


/********** External Includes **********/


/********** Standard Includes **********/
#include <string>
#include <vector>


namespace Table
{
    class Table
    {
    public:
        Table(unsigned int num_of_row, unsigned int num_of_col, const std::vector<std::vector<std::string>> &entries, std::string empty_fill);
        ~Table() = default;
        void display();
    
    private:
        unsigned int num_of_row;
        unsigned int num_of_col;
        std::vector<unsigned int> col_width;
        std::vector<std::vector<std::string>> entries;
    };
} // namespace Table

#endif  // TABLE_H