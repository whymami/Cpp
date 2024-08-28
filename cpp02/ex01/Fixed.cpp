/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:21:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 13:10:57 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed(void):fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr )
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed = nbr << this->point;
}

Fixed::Fixed(const float nbr )
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed = roundf(nbr * (1 << this->point));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &opCopy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &opCopy)
        this->fixed = opCopy.fixed;
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->fixed / (float)(1 << this->point)));
}

int Fixed::toInt( void ) const
{
    return (roundf(this->fixed / (1 << this->point)));
}

std::ostream &operator<<(std::ostream &str , const Fixed &opCopy)
{
    str << opCopy.toFloat();
    return (str);
}
