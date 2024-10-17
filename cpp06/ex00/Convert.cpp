/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:26:36 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/16 10:34:13 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int ScalarConverter::_type;

void ScalarConverter::printChar(const std::string &str)
{
    if (str == "0")
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    if (str.length() == 1 && std::isprint(str[0]))
    {
        std::cout << "char: '" << str[0] << "'" << std::endl;
        return;
    }
    int num = std::atoi(str.c_str());
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (std::isprint(static_cast<char>(num)))
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}


void ScalarConverter::printInt(const std::string &str)
{
    if (str == "0")
    {
        std::cout << "int: 0" << std::endl;
        return;
    }
    if (str.length() == 1 && std::isprint(str[0]))
    {
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        return;
    }
    long nbr = std::atol(str.c_str());
    if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << nbr << std::endl;
}

void ScalarConverter::handlePseudo(const std::string &str)
{
    std::string pseudos_float[3] = {"-inff", "+inff", "nanf"};
    std::string pseudos_double[3] = {"-inf", "+inf", "nan"};
    for (size_t i = 0; i < 3; i++)
    {
        if (str == pseudos_float[i] || str == pseudos_double[i])
        {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << pseudos_float[i] << std::endl;
            std::cout << "double: " << pseudos_double[i] << std::endl;
        }
    }
}

void ScalarConverter::printFloat(const std::string &str)
{
    if (_type == FLOAT || _type == DOUBLE)
    {
        size_t precision = 0;
        bool hasDot = false;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                hasDot = true;
                i++;
                while (i < str.length() && str[i] != 'f' && str[i] != 'F' && precision++)
                    i++;
                break;
            }
        }
        if (!hasDot || precision == 0)
            precision = 1;
        std::cout << std::fixed << std::setprecision(precision) << "float: " << std::atof(str.c_str()) << "f" << std::endl;
    }
    else if (_type == INT || _type == CHAR)
    {
        if (_type == CHAR && str.length() == 1)
        {
            char c = str[0];
            float floatVal = static_cast<float>(c);
            std::cout << "float: " << floatVal << ".0f" << std::endl;
        }
        else
            std::cout << "float: " << std::atof(str.c_str()) << ".0f" << std::endl;
    }
}


void ScalarConverter::printDouble(const std::string &str) 
{
    if (_type == FLOAT || _type == DOUBLE)
    {
        size_t precision = 0;
        bool hasDot = false;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                hasDot = true;
                i++;
                while (i < str.length() && str[i] != 'f' && str[i] != 'F' && precision++)
                    i++;
                break;
            }
        }
        if (!hasDot || precision == 0)
            precision = 1;
        std::cout << std::fixed << std::setprecision(precision) << "double: " << std::atof(str.c_str()) << std::endl;
    }
    else if (_type == INT || _type == CHAR)
    {
        if (_type == CHAR && str.length() == 1)
        {
            char c = str[0];
            double doubleVal = static_cast<double>(c);
            std::cout << "double: " << doubleVal << ".0" << std::endl;
        }
        else
            std::cout << "double: " << std::atof(str.c_str()) << ".0" << std::endl;
    }
}


void ScalarConverter::convert(const std::string &str)
{
    _type = checkInput(str);
    switch (_type)
    {
        case PSEUDO:
            handlePseudo(str);
            break;
        case CHAR:
            printChar(str);
            printInt(str);
            printFloat(str);
            printDouble(str);
            break;
        case EMPTY:
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: 0" << std::endl;
            std::cout << "float: 0.0f" << std::endl;
            std::cout << "double: 0.0" << std::endl;
            break;
        case INT:
            printChar(std::to_string(std::atoi(str.c_str())));
            printInt(str);
            printFloat(str);
            printDouble(str);
            break;
        case FLOAT:
            printChar(std::to_string(std::atoi(str.c_str())));
            printInt(str);
            printFloat(str);
            printDouble(str);
            break;
        case DOUBLE:
            printChar(std::to_string(std::atoi(str.c_str())));
            printInt(str);
            printFloat(str);
            printDouble(str);
            break;
        default:
            std::cout << "Error: invalid input" << std::endl;
            break;
    }
}
