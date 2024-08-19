/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:53:14 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 17:10:32 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "iostream"

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name);
        ~Zombie( void );
        void announce( void );
        Zombie *newZombie(std::string name);
        void randomChump(std::string name);
};

#endif
