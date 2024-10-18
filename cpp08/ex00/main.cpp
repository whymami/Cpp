/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:55:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/18 16:44:51 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    {
        try
        {
            std::list<int> l;
            l.push_back(1);
            l.push_back(2);
            l.push_back(3);
            l.push_back(4);
            l.push_front(5);
            std::list<int>::const_iterator it = ::easyfind(l, 5);
            std::cout << *it << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}