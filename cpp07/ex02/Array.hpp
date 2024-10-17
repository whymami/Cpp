/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:59:54 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/17 13:48:44 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"

template <class T>
class Array
{
    private:
        T *_arr;
        unsigned int _n;
    public:
        Array();
        Array(unsigned int n);
        Array<T> &operator=(const Array<T> &other);
        T &operator[](const unsigned int inx);
        Array(Array &other);    
        ~Array();

    class OutOfRangeException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#include "Array.tpp"
#endif