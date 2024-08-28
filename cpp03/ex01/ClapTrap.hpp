/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:31:02 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 17:15:20 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include "iostream"

class ClapTrap
{
    protected:
        std::string _name;
        int _HitPoints;
        int _EnergyPoints;
        int _AttackDamage;
    public:
        virtual void attack(const std::string& target);
        virtual void takeDamage(unsigned int amount);
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
        void setAttackDamage(int amount);
        virtual ~ClapTrap();
};

#endif
