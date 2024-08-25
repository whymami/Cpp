/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:44:31 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/25 20:48:04 by muguveli         ###   ########.fr       */
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
};

#endif
