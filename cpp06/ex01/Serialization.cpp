/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:17:00 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/15 16:49:37 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
    
}

Serialization &Serialization::operator=(Serialization &other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

Serialization::Serialization(Serialization &other)
{
    *this = other;
}

uintptr_t Serialization::serialize(Data* ptr)
{
    uintptr_t point = reinterpret_cast<uintptr_t>(ptr);
    return (point);
}

Data* Serialization::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data*>(raw);
    return (data);
}

Serialization::~Serialization() 
{
    
}
