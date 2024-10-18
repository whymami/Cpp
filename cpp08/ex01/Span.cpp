/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:19 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/18 19:13:12 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Span.hpp"

Span::Span() : _n(0) , _vector(std::vector<int>()) {}

Span::Span(unsigned int n) : _n(n), _vector(std::vector<int>()){}

Span &Span::operator=(Span &other) 
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

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        if (_vector.size() >= _n)
            throw std::runtime_error("Vector range is overflow");
        _vector.push_back(*begin);
        begin++;
    }
}

Span::Span(Span &other) {*this = other;}

const char *Span::VectorIsFull::what() const throw()
{
    return ("Cannot add more numbers, limit reached.");    
}

int Span::shortestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("At least two numbers are required to find a span.");
    std::sort(_vector.begin(), _vector.end());
    int min = _vector[0] - _vector[1];
    for (size_t i = 2; i < _vector.size(); i++)
        if (_vector[i] - _vector[i - 1] < min)
            min = _vector[i] - _vector[i - 1];
    if (min < 0)
        return (min *= -1);
    return (min);
}

int Span::longestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("At least two numbers are required to find a span.");
    std::sort(_vector.begin(), _vector.end());
    int max = _vector[0] - _vector[1];
    for (size_t i = 1; i < _vector.size(); i++)
        if (_vector[i] + _vector[i - 1] > max)
            max = _vector[i] + _vector[i - 1];
    if (max < 0)
        return (max *= -1);
    return (max);
}

Span::~Span() {}