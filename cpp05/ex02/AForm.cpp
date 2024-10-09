/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:30:32 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:46:14 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("mami"), _requiredSignGrade(150), _requiredExecGrade(150) {}

AForm::AForm(const std::string name, bool isSigned, const int requiredSignGrade, const int requiredExecGrade) : _name(name), _requiredSignGrade(requiredSignGrade), _requiredExecGrade(requiredExecGrade)
{
	if (requiredExecGrade > 150 || requiredSignGrade > 150)
		throw AForm::GradeTooLowException();
	else if (requiredExecGrade < 0 || requiredSignGrade < 0)
		throw AForm::GradeTooHighException();
	else
    	this->_isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
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

AForm &AForm::operator=(const AForm &other)
{    
	if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

AForm::AForm(const AForm &other) : _name(other.getName()), _requiredSignGrade(other.getRequiredSignGrade()), _requiredExecGrade(other.getRequiredExecGrade())
{
	*this = other;
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}

int AForm::getRequiredSignGrade() const
{
    return (this->_requiredSignGrade);
}

int AForm::getRequiredExecGrade() const
{
    return (this->_requiredExecGrade);
}

AForm::~AForm() {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("<Form> grade too low");
}

const char *AForm::FormAlreadySiged::what() const throw()
{
	return("Form is already signed");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("<Form> grade too high");
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
	os << "Form: " << f.getName() << ", signed: " << f.getIsSigned() << ", Grade: to sign: " << f.getRequiredSignGrade() << ", Grade to request: " << f.getRequiredExecGrade();
	return (os);
}
