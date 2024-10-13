/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:27:37 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/13 18:26:46 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Convert.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Usage: ./convert <input>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);

    return 0;
}
