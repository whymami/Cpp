/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:31:36 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/20 19:42:08 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->get_type() << std::endl;
}

HumanB::HumanB(std::string name)
{
    if (name.empty())
    {
        while (true)
        {
            std::cout << "Name cannot be left empty" << std::endl;
            std::cout << "> ";
            getline(std::cin, name);
            if (std::cin.eof())
                return ;
            if (name.empty())
                continue;
            else
                break;
        }
    }
    this->name = name;
}

HumanB::~HumanB()
{
    return ;
}

void HumanB::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}

