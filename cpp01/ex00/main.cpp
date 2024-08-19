/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:42:51 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 16:14:55 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
    Zombie deneme("mami");
    deneme.announce();

    Zombie *deneme1;

    deneme1 = new Zombie("whymami");
    deneme1->announce();
    deneme1->randomChump("sa");
    delete (deneme1);
}
