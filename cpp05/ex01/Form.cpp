/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:30:32 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/08 15:57:15 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("mami")
{
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}

int Form::getRequiredSignGrade() const
{
    return (this->requiredSignGrade);
}

int Form::getRequiredExecGrade() const
{
    return (this->requiredExecGrade);
}
