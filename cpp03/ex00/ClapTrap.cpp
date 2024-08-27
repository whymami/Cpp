
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    this->_name = name;
    std::cout << getName() << " ClapTrap Constructor called!" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called!" << std::endl;
    *this = copy;
}

ClapTrap::ClapTrap() : _name("whymami"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_AttackDamage = other._AttackDamage;
        this->_EnergyPoints = other._EnergyPoints;
        this->_HitPoints = other._HitPoints;
        this->_name = other._name;
    }
    return *this;
}

std::string ClapTrap::getName(void) 
{
    return (this->_name);
}

int ClapTrap::getAttackDamage(void)
{
    return (this->_AttackDamage);
}

ClapTrap::~ClapTrap()
{
    std::cout << getName() << " Destructor called" << std::endl;
}

int ClapTrap::getEnergyPoint(void)
{
    return (this->_EnergyPoints);
}

int ClapTrap::getHitPoint(void)
{
    return (this->_HitPoints);
}

void ClapTrap::setHitPoint(unsigned int amount)
{
    this->_HitPoints = amount;
}

void ClapTrap::setEnergyPoint(int amount)
{
    this->_EnergyPoints = amount;
}

void ClapTrap::attack(const std::string& target)
{
    if (getHitPoint() > 0 && getEnergyPoint() > 0 && this->_EnergyPoints--)
        std::cout << "ClapTrap " + getName() + " attacks " << target << ", causing " << getAttackDamage() << "points of damage" << std::endl;
    else if (getEnergyPoint() == 0)
        std::cout << "ClapTrap " << getName() << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ClapTrap " << getName() << " is not able to attack " << target << ", because he has no hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoint() > 0 && getHitPoint() > 0 && getHitPoint() + amount <= 10)
    {
        setHitPoint(getHitPoint() + amount);
        std::cout << "ClapTrap " << getName() << " repaired itself and gained " << amount << " of hit points, he now has " << getHitPoint() << "hit points." << std::endl;
        setEnergyPoint(getEnergyPoint() - 1);
        return;
    }
    if (getEnergyPoint() == 0)
        std::cout << "ClapTrap " << getName() << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
    else if (getHitPoint() == 0)
        std::cout << "ClapTrap " << getName() << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
    else
        std::cout << "ClapTrap " << getName() << " can't be repaired to have more than 10 hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoint() > 0)
    {
        if (getHitPoint() - amount > 0)
            setHitPoint(getHitPoint() - amount);
        else
            setHitPoint(0);
        std::cout << "ClapTrap " << getName() << " was attacked and lost " << amount << " hit points, he now has " << getHitPoint() << " hit points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->getName() << " is already dead!" << std::endl;
}
