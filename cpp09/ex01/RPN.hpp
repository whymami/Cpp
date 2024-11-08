/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:15:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/31 18:01:52 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "iostream"
#include "stack"
#include <sstream>

class RPN
{
    private:
        std::stack<double> _rpn;
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