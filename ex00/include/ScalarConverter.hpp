#pragma once

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter(void);
    public:
        static void     convert(const std::string &literal);
};
