/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:31:32 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/24 19:38:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceFile.hpp"

void init_program(char **argv)
{
    replaceFile replace_file(argv[1], argv[2], argv[3]);
}

int main (int argc, char **argv)
{
    if (argc == 4)
        init_program(argv);
    else
        return (std::cout << "The program must take 3 arguments." << std::endl, 0);
    
}
