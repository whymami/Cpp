/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:18:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 13:14:05 by muguveli         ###   ########.fr       */
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
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed(const int nbr);
    Fixed(const float nbr);
    Fixed &operator=(const Fixed &opCopy);
    bool operator>(const Fixed &opCopy) const;
    bool operator<(const Fixed &opCopy) const;
    bool operator>=(const Fixed &opCopy) const;
    bool operator<=(const Fixed &opCopy) const;
    bool operator==(const Fixed &opCopy) const;
    bool operator!=(const Fixed &opCopy) const;
    Fixed operator+(const Fixed &opCopy) const;
    Fixed operator-(const Fixed &opCopy) const;
    Fixed operator*(const Fixed &opCopy) const;
    Fixed operator/(const Fixed &opCopy) const;
    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy);

#endif
