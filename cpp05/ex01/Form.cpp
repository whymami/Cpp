/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:30:32 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:29:13 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("mami"), _requiredSignGrade(150), _requiredExecGrade(150)
{
}

Form::Form(const std::string name, bool isSigned, const int requiredSignGrade, const int requiredExecGrade) : _name(name), _requiredSignGrade(requiredSignGrade), _requiredExecGrade(requiredExecGrade)
{
	if (requiredExecGrade > 150 || requiredSignGrade > 150)
		throw Form::GradeTooLowException();
	else if (requiredExecGrade < 0 || requiredSignGrade < 0)
		throw Form::GradeTooHighException();
	else
    	this->_isSigned = isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredSignGrade())
		throw GradeTooLowException();
	else if (this->getIsSigned())
		throw FormAlreadySiged();
	else
	{
		std::cout << "Form was signed by " << bureaucrat.getName() << std::endl;
		this->_isSigned = true;
	}
}

Form &Form::operator=(const Form &other)
{    
	if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

Form::Form(const Form &other) : _name(other.getName()), _requiredSignGrade(other.getRequiredSignGrade()), _requiredExecGrade(other.getRequiredExecGrade())
{
	*this = other;
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
    return (this->_requiredSignGrade);
}

int Form::getRequiredExecGrade() const
{
    return (this->_requiredExecGrade);
}

Form::~Form()
{	
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("<Form> grade too low");
}

const char *Form::FormAlreadySiged::what() const throw()
{
	return("Form is already signed");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("<Form> grade too high");
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
	os << "Form: " << f.getName() << ", signed: " << f.getIsSigned() << ", Grade: to sign: " << f.getRequiredSignGrade() << ", Grade to request: " << f.getRequiredExecGrade();
	return (os);
}
