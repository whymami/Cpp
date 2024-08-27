/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:10:03 by muguveli          #+#    #+#             */
/*   Updated: 2024/08/26 18:17:28 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float alan;
    float p_alan1;
    float p_alan2;
    float p_alan3;

    alan = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
    if (alan < 0)
        alan *= -1;
    p_alan1 = ((point.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + (b.getX().toFloat() * (c.getY().toFloat() - point.getY().toFloat())) + (c.getX().toFloat() * (point.getY().toFloat() - b.getY().toFloat()))) / 2;
    if (p_alan1 < 0)
        p_alan1 *= -1;
    p_alan2 = ((a.getX().toFloat() * (point.getY().toFloat() - c.getY().toFloat())) + (point.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - point.getY().toFloat()))) / 2;
    if (p_alan2 < 0)
        p_alan2 *= -1;
    p_alan3 = ((a.getX().toFloat() * (b.getY().toFloat() - point.getY().toFloat())) + (b.getX().toFloat() * (point.getY().toFloat() - a.getY().toFloat())) + (point.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
    if (p_alan3 < 0)
        p_alan3 *= -1;

    if (p_alan1 == 0 || p_alan2 == 0 || p_alan3 == 0)
        return (false);
    if (p_alan1 + p_alan2 + p_alan3 == alan)
        return (true);
    return (false);
}
