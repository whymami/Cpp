/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:13:06 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 20:01:06 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->name << "attacks with their " << this->weapon.get_type() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
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

HumanA::~HumanA()
{
    return;
}
