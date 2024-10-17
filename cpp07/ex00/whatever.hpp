/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:26:10 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/17 11:35:10 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename T>
void swap(T&a, T&b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T&a, T&b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T max(T&a, T&b)
{
    if (a > b)
        return (a);
    return (b);
}
#endif