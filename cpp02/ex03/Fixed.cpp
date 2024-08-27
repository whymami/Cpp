/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:21:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/26 16:41:04 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed(void) : fixed(0)
{
}

Fixed::Fixed(const int nbr)
{
    this->fixed = nbr << this->point;
}

Fixed::Fixed(const float nbr)
{
    this->fixed = roundf(nbr * (1 << this->point));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &opCopy)
{
    if (this != &opCopy)
        this->fixed = opCopy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)(this->fixed / (float)(1 << this->point)));
}

int Fixed::toInt(void) const
{
    return (roundf(this->fixed / (1 << this->point)));
}

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy)
{
    str << opCopy.toFloat();
    return (str);
}

bool Fixed::operator>(const Fixed &opCopy) const
{
    return (this->fixed > opCopy.fixed);
}

bool Fixed::operator<(const Fixed &opCopy) const
{
    return (this->fixed < opCopy.fixed);
}

bool Fixed::operator>=(const Fixed &opCopy) const
{
    return (this->fixed >= opCopy.fixed);
}

bool Fixed::operator<=(const Fixed &opCopy) const
{
    return (this->fixed <= opCopy.fixed);
}

bool Fixed::operator==(const Fixed &opCopy) const
{
    return (this->fixed == opCopy.fixed);
}

bool Fixed::operator!=(const Fixed &opCopy) const
{
    return (this->fixed != opCopy.fixed);
}

Fixed Fixed::operator+(const Fixed &opCopy) const
{
    Fixed result;

    result.setRawBits(this->fixed + opCopy.fixed);
    return (result);
}

Fixed Fixed::operator-(const Fixed &opCopy) const
{
    Fixed result;

    result.setRawBits(this->fixed - opCopy.fixed);
    return (result);
}

Fixed Fixed::operator*(const Fixed &opCopy) const
{
    Fixed result;

    result.setRawBits((this->fixed * opCopy.fixed) >> this->point);
    return (result);
}

Fixed Fixed::operator/(const Fixed &opCopy) const
{
    Fixed result;

    result.setRawBits((this->fixed << this->point) / opCopy.fixed);
    return (result);
}

Fixed &Fixed::operator++()
{
    ++this->fixed;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed result;

    result = *this;
    this->fixed++;
    return (result);
}

Fixed &Fixed::operator--()
{
    --this->fixed;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed result;

    result = *this;
    this->fixed--;
    return (result);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}
