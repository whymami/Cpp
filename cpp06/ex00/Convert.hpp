/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:00:21 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/13 19:32:31 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iomanip>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define EMPTY 5
#define PSEUDO 6
#define ERROR -1

class ScalarConverter 
{
private:
    static int _type;
    static int checkInput(const std::string &str);;
    static void printChar(const std::string &str);
    static void printInt(const std::string &str);
    static void printFloat(const std::string &str);
    static void printDouble(const std::string &str);
    static void handlePseudo(const std::string &str);
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter();
    static void convert(const std::string &str);
};

#endif
