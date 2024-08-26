/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:45:14 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/26 17:42:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "iostream"
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &copy);
        Point &operator=(const Point &pointCopy);
        ~Point();
        Fixed const &getX() const;
        Fixed const &getY() const;
};

#endif
