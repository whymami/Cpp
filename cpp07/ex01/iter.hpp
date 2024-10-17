/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:38:27 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/17 14:05:53 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template <typename T1, typename T2>
void iter(T1 *arr, size_t arrLen, void(*func)(T2 &))
{
    for (size_t i = 0; i < arrLen; i++)
        func(arr[i]);
}
#endif