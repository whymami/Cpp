/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:42:56 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/20 19:56:09 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "iostream"
#include "fstream"
#include <sstream>
#include "map"

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        std::string _inputFilePath;
        std::fstream _fileData;
        std::fstream _fileInput;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string inputFilePath);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        void initData();
        void checkFile();
        void cmpInput();
};