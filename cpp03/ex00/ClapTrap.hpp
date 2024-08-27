

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include "iostream"

class ClapTrap
{
    private:
        std::string _name;
        int _HitPoints;
        int _EnergyPoints;
        int _AttackDamage;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);

        std::string getName( void );
        int getAttackDamage( void );
        int getHitPoint( void );
        int getEnergyPoint( void );

        void setHitPoint(unsigned int amount);
        void setEnergyPoint(int amount);
        ~ClapTrap();
};

#endif
