/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:21:20 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/31 17:35:52 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

bool signControl(char s) {
    return (s == '+');
}

bool digitControl(const std::string& input) {
    for (size_t j = 0; j < input.size(); j++) {
        if (!std::isdigit(input[j]) && input[j] != ' ')
            if (!signControl(input[j]) || (j + 1 < input.size() && !std::isdigit(input[j + 1])))
                return false;
    }
    return true;
}

void PmergeMe::parser(char **av) {
    for (size_t i = 1; av[i]; ++i) {
        _input += av[i];
        if (av[i + 1]) _input += " ";
    }
    if (!digitControl(_input))
        throw std::runtime_error("error: Invalid input.");
    std::istringstream iss(_input);
    std::string a;
    while (iss >> a) {
        _vector.push_back(std::atoi(a.c_str()));
        _deque.push_back(std::atoi(a.c_str()));
    }
}

template <typename T>
void PmergeMe::mergeSort(T &c, const T &left, const T &right) 
{
    c.clear();
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            c.push_back(left[i++]);
        else
            c.push_back(right[j++]);
    }
    while (i < left.size())
        c.push_back(left[i++]);

    while (j < right.size())
        c.push_back(right[j++]);
}

template <typename T>
void PmergeMe::FordJohnson(T &c) 
{
    if (c.size() <= 1)
        return;
    
    T left(c.begin(), c.begin() + c.size() / 2);
    T right(c.begin() + c.size() / 2, c.end());

    FordJohnson(left);
    FordJohnson(right);

    mergeSort(c, left, right); 
}

template <typename T, typename J>
void PmergeMe::display(const T &c, const J &c1, std::clock_t start, std::clock_t end, std::clock_t start1, std::clock_t end1)
{
    std::cout << "before: " << _input << std::endl; 
    std::cout << "After: ";
    for (typename T::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    double t1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    double t2 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    std::cout << "Time to process a range of " << c.size() << " elements with std::vector : " << t1 << " us" << std::endl;
    std::cout << "Time to process a range of " << c1.size() << " elements with std::deque : " << t2 << " us" << std::endl;
}

PmergeMe::PmergeMe(char **av) : _vector(std::vector<int>()), _deque(std::deque<int>()) {
    parser(av);
    std::clock_t start = std::clock();
    FordJohnson(_vector);
    std::clock_t end = std::clock();

    std::clock_t start1 = std::clock();
    FordJohnson(_deque);
    std::clock_t end1 = std::clock();
    
    display(_deque, _vector, start, end, start1, end1);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) 
    {
        this->_input = other._input;
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe::~PmergeMe() {}
