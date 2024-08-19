/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:42:51 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 18:03:59 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
    Zombie zombi("temp");

    Zombie *deneme = zombi.zombieHorde(5, "mami");
    for (int i = 0; i < 5; i++)
        deneme[i].announce();
    delete [] deneme;
}
