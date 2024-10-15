/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:35:50 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/15 16:49:13 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <iostream>

struct Data
{
    std::string str;
    int value;
};

class Serialization
{
    public:
        Serialization();
        Serialization(Serialization &other);
        Serialization &operator=(Serialization &other);  
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serialization();
};

#endif
