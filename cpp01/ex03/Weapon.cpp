/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:51:16 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 19:57:00 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Weapon.hpp"

const std::string Weapon::get_type()
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(std::string type)
{
    if (type.empty())
    {
        while (true)
        {
            std::cout << "The weapon cannot be left empty" << std::endl;
            std::cout << "> ";
            getline(std::cin, type);
            if (std::cin.eof())
                return ;
            if (type.empty())
                continue;
            else
                break;
        }
    }
    this->setType(type);
}

Weapon::~Weapon()
{
    return;
}
