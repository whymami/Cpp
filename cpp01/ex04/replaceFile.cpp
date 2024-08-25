/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacefile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/25 12:34:47 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceFile.hpp"

void replaceFile::setFilename(std::string filename)
{
    if (filename.empty())
    {
        while (true)
        {
            std::cout << "Filename cannot be left empty" << std::endl;
            std::cout << "> ";
            getline(std::cin, filename);
            if (std::cin.eof())
                return;
            if (filename.empty())
                continue;
            else
                break;
        }
    }
    this->filename = filename;
}

void replaceFile::setS1(std::string s1)
{
    if (s1.empty())
    {
        while (true)
        {
            std::cout << "s1 cannot be left empty" << std::endl;
            std::cout << "> ";
            getline(std::cin, s1);
            if (std::cin.eof())
                return;
            if (s1.empty())
                continue;
            else
                break;
        }
    }
    this->s1 = s1;
}

void replaceFile::setS2(std::string s2)
{
    if (s2.empty())
    {
        while (true)
        {
            std::cout << "s2 cannot be left empty" << std::endl;
            std::cout << "> ";
            getline(std::cin, s2);
            if (std::cin.eof())
                return;
            if (s2.empty())
                continue;
            else
                break;
        }
    }
    this->s2 = s2;
}

std::string const replaceFile::getFilename(void)
{
    return (this->filename);
}

std::string const replaceFile::getS1(void)
{
    return (this->s1);
}

std::string const replaceFile::getS2(void)
{
    return (this->s2);
}

void replaceFile::writeFile()
{
    size_t pos = 0;
    size_t prevPos = 0;

    while ((pos = this->buffer.find(this->getS1(), pos)) != std::string::npos)
    {
        this->result.append(this->buffer, prevPos, pos - prevPos);
        this->result.append(this->getS2());
        pos += this->getS1().length();
        prevPos = pos;
    }
    result.append(buffer, prevPos, std::string::npos);

    this->replacedfile << this->result;
    this->replacedfile.close();
}

replaceFile::replaceFile(std::string filename, std::string s1, std::string s2)
{
    setFilename(filename);
    setS1(s1);
    setS2(s2);

    this->file.open(this->getFilename().c_str(), std::ios::in);
    if (!this->file.is_open())
    {
        std::cout << "File could not open" << std::endl;
        return;
    }
    std::getline(this->file, buffer, '\0');
    this->file.close();

    this->replacedfile.open(this->getFilename() + ".replace", std::ios::out);
    if (!this->replacedfile.is_open())
    {
        std::cout << "Output file could not be opened" << std::endl;
        return;
    }
    writeFile();
}
