/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:41:30 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/20 19:45:21 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("");
        HumanA bob("", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("");
        HumanB jim("Jim");
        jim.setWeapon(&club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}
