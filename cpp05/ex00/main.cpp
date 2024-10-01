/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:08:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/09/30 19:01:38 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("mami", 1);
        Bureaucrat b("akoluk", 149);
        std::cout << a << std::endl;
        a.gradeDown();
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        b.gradeDown();
        std::cout << b << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}