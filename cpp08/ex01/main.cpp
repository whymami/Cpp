/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:55:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/19 11:24:17 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {    
        try
        {
            Span a(5);
            a.addNumber(1);
            a.addNumber(2);
            a.addNumber(3);
            a.addNumber(4);
            a.addNumber(5);
            std::cout << "long range: " << a.longestSpan() << std::endl;
            std::cout << "short range: " << a.shortestSpan() << std::endl;
            a.addNumber(6);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }
    
    {
        try
        {
            Span a(10);
            a.addNumber(10, 100);
            std::cout << a.shortestSpan() << std::endl;
            std::cout << a.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}