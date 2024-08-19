/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:09:13 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/19 20:01:10 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include "iostream"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        void attack();
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
};

#endif
