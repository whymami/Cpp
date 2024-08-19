/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:47:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 19:43:12 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include "iostream"

class Weapon
{
    private :
        std::string type;
    public :
        Weapon();
        ~Weapon();
        Weapon(std::string type);
        const std::string get_type(void);
        void setType(std::string type);
};

#endif
