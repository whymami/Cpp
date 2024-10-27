/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:15:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/27 16:54:28 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "iostream"
#include "stack"
#include <sstream>

class RPN
{
    private:
        std::stack<int> _rpn;
    public :
        RPN();
        RPN(std::string input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void addStack(std::string combinedInput);
        void operation(std::string &op);
        void printResult();
};