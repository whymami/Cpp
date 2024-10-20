/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:19 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/20 17:29:13 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Span.hpp"

Span::Span() : _n(0) , _vector(std::vector<int>()) {}

Span::Span(unsigned int n) : _n(n), _vector(std::vector<int>()){}

Span &Span::operator=(const Span &other) 
{
    this->_n  = other._n;
    this->_vector = other._vector;
    return (*this);
}

void Span::addNumber(int number)
{
    if (_vector.size() >= _n)
        throw VectorIsFull();
    _vector.push_back(number);
}

void Span::addNumber(size_t size, size_t seed)
{
    if (_vector.size() >= _n)
        throw VectorIsFull();
    if (size > _n)
        throw std::runtime_error("size exceeds the max limit of the vector");
    for (size_t i = 0; i < size && _vector.size() < _n; i++)
        _vector.push_back(rand() % seed);
}

Span::Span(const Span &other) {*this = other;}

const char *Span::VectorIsFull::what() const throw()
{
    return ("Cannot add more numbers, limit reached.");    
}

int Span::shortestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("At least two numbers are required to find a span.");
    std::sort(_vector.begin(), _vector.end());
    int min = _vector[1] - _vector[0];
    for (size_t i = 2; i < _vector.size(); i++)
        if (_vector[i] - _vector[i - 1] < min)
            min = _vector[i] - _vector[i - 1];
    return (min);
}

int Span::longestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("At least two numbers are required to find a span.");
    std::sort(_vector.begin(), _vector.end());
    return (_vector.at(_vector.size() - 1) - _vector.at(0));
}

Span::~Span() {}