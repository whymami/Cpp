/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckInput.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:15:30 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/16 10:16:25 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

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