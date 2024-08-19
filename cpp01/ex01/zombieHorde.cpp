/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:07:06 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 17:56:27 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde( int N, std::string name )
{
    Zombie* zombies = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        zombies[i] = Zombie(name);
    return (zombies);
}



