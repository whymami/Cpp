/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:31:33 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 13:31:39 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a;
    ClapTrap b("b");

    a.attack("b");
    a.takeDamage(1);
    a.takeDamage(1);
    a.takeDamage(1);
    a.takeDamage(1);
    a.takeDamage(1);
    b.attack("a");
    b.takeDamage(1);

    a.beRepaired(5);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);
    b.takeDamage(1);

    b.beRepaired(10);
    b.attack("a");
    a.attack("b");
    a.attack("b");
    a.takeDamage(1);
    a.takeDamage(1);
    a.takeDamage(1);
    a.takeDamage(1);
}
