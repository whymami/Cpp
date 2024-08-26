/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:18:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/26 14:41:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
    private:
        int fixed;
        static const int point = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &opCopy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed(const int nbr );
        Fixed(const float nbr );

};

std::ostream &operator<<(std::ostream &str , const Fixed &opCopy);

#endif

