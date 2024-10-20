/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:03:21 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/20 19:54:53 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string inputFilePath) : _inputFilePath(inputFilePath)
{
    initData();
    cmpInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _inputFilePath = other._inputFilePath;
    }
    return *this;
}

void BitcoinExchange::initData()
{
    checkFile();
    std::string line;
    std::getline(_fileData, line);
    while (std::getline(_fileData, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            std::string date = line.substr(0, commaPos);
            std::string exchangeRateStr = line.substr(commaPos + 1);
            std::istringstream iss(exchangeRateStr);
            double exchangeRate;
            iss >> exchangeRate;
            _data[date] = exchangeRate;
        }
    }
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char dash1, dash2;

    std::istringstream iss(date);
    iss >> year >> dash1 >> month >> dash2 >> day;

    if (iss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}

void BitcoinExchange::cmpInput()
{
std::string line;

    std::getline(_fileInput, line);

    while (std::getline(_fileInput, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));

        std::istringstream iss(valueStr);
        double inputValue;


        if (!isValidDate(date))
        {
            std::cout << "Error: invalid date => " << date << std::endl;
            continue;
        }
        
        if (!(iss >> inputValue))
        {
            std::cout << "Error: bad input value => " << valueStr << std::endl;
            continue;
        }

        if (inputValue < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (inputValue > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator dataIt = _data.find(date);
        if (dataIt == _data.end())
        {
            dataIt = _data.lower_bound(date);
            if (dataIt != _data.begin()) 
                --dataIt;
            else
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
        }

        double exchangeRate = dataIt->second;
        std::cout << date << " => " << inputValue << " = " << (inputValue * exchangeRate) << std::endl;
    }
}


void BitcoinExchange::checkFile()
{
    _fileData.open("data.csv");
    if (!_fileData.is_open())
        throw std::runtime_error("data.csv not found");
    _fileInput.open(_inputFilePath);
    if (!_fileInput.is_open())
        throw std::runtime_error("input file not found");
}

BitcoinExchange::~BitcoinExchange()
{
    if (_fileData.is_open())
        _fileData.close();
    if (_fileInput.is_open())
        _fileInput.close();
}