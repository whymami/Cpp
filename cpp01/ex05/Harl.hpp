/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:43:36 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/24 20:52:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include "iostream"
#include "string"

class Harl
{
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void complain( std::string level );
};


void (this->*Harl::func[])(void)={
    &Harl::debug, 
    &Harl::info, 
    &Harl::warning, 
    &Harl::error, 
}


#endif