/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:46:58 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 18:53:55 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap Constructor called" << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << this->getName() << " FragTrap Constructor called" << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_AttackDamage = other._AttackDamage;
        this->_EnergyPoints = other._EnergyPoints;
        this->_HitPoints = other._HitPoints;
        this->_name = other._name;
    }
    return *this;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap Copy constructor for " << this->getName() << std::endl;
    *this = other;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << ": You want a high five?" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructors for "<< this->getName() << std::endl;
}
