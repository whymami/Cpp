/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:08:44 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 18:24:38 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main(void)
{
    std::string str =   "HI THIS IS BRAIN";

    std::string *strptr = &str;
    std::string &ref = str;

    std::cout << "stringPTR address: " << &strptr << std::endl;
    std::cout << "stringin  address: " << &str << std::endl;
    std::cout << "stringREF address: " << &ref << std::endl;
}