/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:52:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/17 14:07:51 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void upperCase(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void convertToInt(char &c)
{ 
    std::cout << "char : " << c << " int value: " << static_cast<int>(c) << std::endl;
}

int main(void)
{
    char a[]= "muguveli";
    ::iter(a, sizeof(a), *upperCase);
    std::cout << a << std::endl;
    ::iter(a, sizeof(a), *convertToInt);
}