/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:30:54 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 17:04:35 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "iostream"
# include "ClapTrap.hpp"
 
class ScavTrap : public ClapTrap
{
    private:
        bool _isGuard;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        void guardGate(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        ~ScavTrap();
};

#endif
