/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:56:29 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 18:06:44 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::get_name( void )const
{
    return (this->name);
}

Zombie::Zombie (std::string name)
{
    this->name = name;
}

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie()
{
    return ;
}

void Zombie::announce( void )
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
