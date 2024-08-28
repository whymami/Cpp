/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:04 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/28 13:15:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &copy) : _x(copy._x) , _y(copy._y) {}

Point &Point::operator=(const Point &pointCopy)
{
    if (this != &pointCopy)
       // assigment implementation
    return *this;
}

Point::Point() : _x(0) , _y(0) {}

Point::~Point() {}

Fixed const &Point::getX() const
{
    return (this->_x);
}

Fixed const &Point::getY() const
{
    return (this->_y);
}
