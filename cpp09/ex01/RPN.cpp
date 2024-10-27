/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:15:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/27 17:19:46 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "string"

RPN::RPN() {}

bool signControl(char s)
{
    return (s == '+' || s == '-' || s == '*' || s == '/');
}

bool digitControl(const std::string& input)
{
    for (size_t j = 0; j < input.size(); j++)
        if (!std::isdigit(input[j]) && input[j] != ' ')
            if (!signControl(input[j]))
                return false;
    return true;
}

void RPN::operation(std::string &op)
{
    if (_rpn.size() < 2)
        throw std::runtime_error("Error");
    
    int nbr2 = _rpn.top();
    _rpn.pop();
    int nbr1 = _rpn.top();
    _rpn.pop();

    switch (op[0])
    {
    case '+':
        _rpn.push(nbr1 + nbr2);
        break;
    case '-':
        _rpn.push(nbr1 - nbr2);
        break;
    case '*':
        _rpn.push(nbr1 * nbr2);
        break;
    case '/':
        if (nbr2 == 0)
            throw std::runtime_error("Error");
        _rpn.push(nbr1 / nbr2);
        break;
    }
}

void RPN::printResult()
{
    if (_rpn.empty())
        throw std::runtime_error("Error");
    
    int size = _rpn.size();
    int result = _rpn.top();
    
    std::cout << "stack size: " << size << std::endl;
    std::cout << "result: " << result << std::endl;
}

RPN::RPN(std::string input)
{
    if (!digitControl(input))
        throw std::runtime_error("Error");
    
    std::istringstream iss(input);
    std::string a;
    
    while (iss >> a)
    {
        if (signControl(a[0]) && a.size() == 1)
        {
            operation(a);
            continue;
        }
        _rpn.push(std::atoi(a.c_str()));
    }
    printResult();
}

RPN::RPN(const RPN &other) 
{
    if (this != &other)
        *this = other;
}

RPN &RPN::operator=(const RPN &other) 
{
    this->_rpn = other._rpn;
    return (*this);
}

RPN::~RPN() {}