#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }

ScalarConverter::~ScalarConverter(void) { }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) { (void)copy; return (*this); }

/*
 * Cette fonction vérifie si la str est un char
 * on vérifie que la str fais bien 1 caractère
 * et on vérifie également que le texte n'est pas
 * un chiffre
 */
static bool     isChar(const std::string &str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

/*
 * Cette fonction vérifie si la str représente un
 * int en base 10, le pointeur end est le premier
 * charactère non converti par strtol
 */
static bool     isInt(const std::string &str)
{
    char *end;
    
    std::strtol(str.c_str(), &end, 10);
    return (*end == '\0');
}

/*
 * Cette fonction vérifie si la str représente un
 * float valide avec f à la fin ou si c'est un
 * pseudo-littéral
 */
static bool     isFloat(const std::string &str)
{
    char *end;

    if (str == "+inff" || str == "-inff" || str == "nanf")
        return (true);
    std::strtof(str.c_str(), &end);
    return (*end == 'f');
}

/*
 * Cette fonction vérifie si la str représente un
 * double valide ou un pseudo-litéral
 */
static bool     isDouble(const std::string &str)
{
    char *end;

    if (str == "+inf" || str == "-inf" || str == "nan")
        return (true);
    std::strtod(str.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::fixed << std::setprecision(1);

    if (isChar(literal))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (isInt(literal))
    {
        long val = std::strtol(literal.c_str(), NULL, 10);

        if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
            std::cout << "char: impossible\n";
        else if (!std::isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(val) << "'\n";
        std::cout << "int: " << val << "\n";
        std::cout << "float: " << static_cast<float>(val) << "f\n";
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else if (isFloat(literal))
    {
        float val = std::strtof(literal.c_str(), NULL);

        if (std::isnan(val) || std::isinf(val))
            std::cout << "char: impossible\nint: impossible\n";
        else
        {
            if (!std::isprint(static_cast<char>(val)))
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: '" << static_cast<char>(val) << "'\n";
            std::cout << "int: " << static_cast<int>(val) << "\n";
        }
        std::cout << "float: " << val << "f\n";
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else if (isDouble(literal))
    {
        double val = std::strtod(literal.c_str(), NULL);

        if (std::isnan(val) || std::isinf(val))
            std::cout << "char: impossible\nint: impossible\n";
        else
        {
            if (!std::isprint(static_cast<char>(val)))
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: '" << static_cast<char>(val) << "'\n";
            std::cout << "int: " << static_cast<int>(val) << "\n";
        }
        std::cout << "float: " << static_cast<float>(val) << "f\n";
        std::cout << "double: " << val << std::endl;
    }
    else {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}