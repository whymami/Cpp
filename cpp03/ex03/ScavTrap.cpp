/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:16:49 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 18:31:58 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor for the name " << this->getName() << " called" << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap default Constructor called" << std::endl;
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructors called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy constructor called!" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_AttackDamage = other._AttackDamage;
        this->_EnergyPoints = other._EnergyPoints;
        this->_HitPoints = other._HitPoints;
        this->_name = other._name;
    }
    return *this;
}

void ScavTrap::guardGate(void)
{
    if (this->_isGuard == false)
    {
        this->_isGuard = true;
        std::cout << "ScavTrap " << this->getName() << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->getName() << " is already guarding the gate." << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    if (this->getHitPoint() > 0 && this->getEnergyPoint() > 0 && this->_EnergyPoints--)
        std::cout << "ScavTrap " + this->getName() + " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage" << std::endl;
    else if (getEnergyPoint() == 0)
        std::cout << "ScavTrap " << this->getName() << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ScavTrap " << this->getName() << " is not able to attack " << target << ", because he has no hit points left." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoint() > 0)
    {
        if (this->getHitPoint() - amount > 0)
            this->setHitPoint(this->getHitPoint() - amount);
        else
            this->setHitPoint(0);
        std::cout << "ScavTrap " << this->getName() << " was attacked and lost " << amount << " hit points, he now has " << this->getHitPoint() << " hit points." << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->getName() << " is already dead!" << std::endl;
}
