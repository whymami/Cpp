/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:21:20 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/27 19:40:58 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}


bool signControl(char s)
{
    return (s == '+' || s == '-');
}

bool digitControl(const std::string& input)
{
    for (size_t j = 0; j < input.size(); j++)
        if (!std::isdigit(input[j]) && input[j] != ' ')
            if (!signControl(input[j]) && !std::isdigit(input[j + 1]))
                return false;
    return true;
}

void PmergeMe::parser(char **av)
{
    for (size_t i = 1; av[i] ; ++i) 
    {
        _input += av[i];
        if (av[i + 1]) _input += " ";
    }
    if (!digitControl(_input))
        throw std::runtime_error("error:");
    std::istringstream iss(_input);
    std::string a;
    while (iss >> a)
    {
        _vector.push_back(std::atoi(a.c_str()));
        _deque.push_back(std::atoi(a.c_str()));
    }
}

template <typename T>
void PmergeMe::mergeSort(T &c, T &left, T &right)
{
    (void)c;
    (void)left;
    (void)right;
    //karşılaştırıp sıralanacak;
}

template <typename T>
void PmergeMe::FordJohnson(T &c)
{
    if (c.size() <= 1)
        return;
    
    T left(c.begin(), c.begin() + c.size() / 2);
    T right(c.begin() + c.size() / 2 , c.end());

    FordJohnson(left);
    FordJohnson(right);

    mergeSort(c, right, left);
}
    
PmergeMe::PmergeMe(char **av) : _vector(std::vector<int>()), _deque(std::deque<int>())
{
    parser(av);
    FordJohnson(_vector);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) 
{
    this->_input = other._input;
    this->_vector = other._vector;
    this->_deque = other._deque;
    return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
    if (this != &other)
        *this = other;
}

PmergeMe::~PmergeMe() {}