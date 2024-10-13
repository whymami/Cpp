/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:26:36 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/13 19:46:06 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int ScalarConverter::_type;


int isInt(const std::string &str)
{
    if (str.empty())
        return 0;
    size_t i = 0;

    if (str[i] == '-' || str[i] == '+') 
        i++;

    if (i == str.length())
        return 0;
    
    for (; i < str.length(); i++)
        if (!std::isdigit(str[i])) 
            return 0;
    return INT;
}

int isChar(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]))
        return CHAR;
    return 0;
}

int isFloat(const std::string &str)
{
    size_t dotCount = 0;
    bool hasF = false;

    if (str.length() == 1)
        return 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            dotCount++;
        else if (str[i] == 'f' || str[i] == 'F')
        {
            if (i != str.length() - 1)
                return 0;
            hasF = true;
        }
        else if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+')
            return 0;
    }
    if (dotCount > 1)
        return 0;
    if (hasF)
        return (FLOAT);
    return 0;
}

int isDouble(const std::string &str)
{
    size_t dotCount = 0;
    if (str.length() == 1)
        return 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            dotCount++;
        else if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+')
            return 0;
    }
    if (dotCount > 1)
        return 0;
    return (DOUBLE);
}
int isPseudo(const std::string &str)
{
    std::string pseudos_float[3] = {"-inff", "+inff", "nanf"};
    std::string pseudos_double[3] = {"-inf", "+inf", "nan"};
    for (size_t i = 0; i < 3; i++)
        if (str == pseudos_float[i] || str == pseudos_double[i])
            return (PSEUDO);
    return (0);        
}

int ScalarConverter::checkInput(const std::string &str)
{
    if (str.empty())
        return EMPTY;
    if (isInt(str))
        return INT;
    if (isPseudo(str))
        return (PSEUDO);
    if (isChar(str))
        return CHAR;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    return 0;
}


void ScalarConverter::printChar(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]))
        std::cout << "char: '" << str[0] << "'" << std::endl;
    else
    {
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
}

void ScalarConverter::printInt(const std::string &str)
{
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
        size_t a = 0;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                i++;
                a = 0;
                while (str[i] && str[i] != 'f' && str[i] != 'F')
                {
                    a++;
                    i++;
                }
                if (a == 0)
                    a = 1;
            }
            else
                a = 1;
        }
        std::cout << std::fixed << std::setprecision(a) << "float: " << std::atof(str.c_str()) << "f" << std::endl;
    }
    else if ((_type == INT || _type == CHAR))
        std::cout << "float: " << std::atof(str.c_str()) << ".0f" << std::endl;
}

void ScalarConverter::printDouble(const std::string &str) 
{
    double num = std::atof(str.c_str());
    std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
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
