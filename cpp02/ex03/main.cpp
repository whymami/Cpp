/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:43:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 13:13:33 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    {
        Point a;
        Point b(0, 10);
        Point c(10, 10);
        Point point(1, 1);
        // false
        std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
    }
        
    {
        Point a;
        Point b(0, 10);
        Point c(10, 10);
        Point point(1, 2);
        // true
        std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
    }
    {
        Point a(1.2, 0);
        Point b(12, 5);
        Point c(-2.5, 0.512);
        Point point(1, 1);
        // true
        std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
    }
        {
        Point a;
        Point b;
        Point c;
        Point point;
        // false
        std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
    }
    {
        Point a;
        Point b(0, 10);
        Point c(10, 10);
        Point point(0, 5);
        // false
        std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
    }
}
