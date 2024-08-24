/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:51:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/24 20:47:09 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP

#include "iostream"
#include "string"
#include "fstream"

class replaceFile
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        std::fstream file;
        std::string result;
        std::fstream replacedfile;
        std::string buffer;

    public:
        replaceFile(std::string filename, std::string s1, std::string s2);
        void setFilename(std::string filename);
        std::string const getFilename(void);
        void setS1(std::string s1);
        std::string const getS1(void);
        void setS2(std::string s2);
        std::string const getS2(void);
        void writeFile();
};

#endif
