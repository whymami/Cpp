/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:13:02 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:55 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
    this->_name = "Diamond_default";
    this->setHitPoint(FragTrap::_HitPoints);
    this->setEnergyPoint(ScavTrap::_EnergyPoints);
    this->setAttackDamage(FragTrap::_AttackDamage);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    std::cout << this->_name << " DiamondTrap Constructor called" << std::endl;
    this->setHitPoint(FragTrap::_HitPoints);
    this->setEnergyPoint(ScavTrap::_EnergyPoints);
    this->setAttackDamage(FragTrap::_AttackDamage);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_AttackDamage = other._AttackDamage;
        this->_EnergyPoints = other._EnergyPoints;
        this->_HitPoints = other._HitPoints;
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Deconstructor for " << this->_name << std::endl;
}
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is " << this->_name << std::endl;
    std::cout << "ClapTrap's name is " << ClapTrap::_name << std::endl;
}
