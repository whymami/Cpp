/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:53:14 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 17:58:41 by muguveli         ###   ########.fr       */
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
        Zombie( std::string name );
        Zombie(void);
        ~Zombie( void );

        void announce( void );
        Zombie* zombieHorde( int N, std::string name );
        std::string get_name( void )const;
};

#endif
