/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:35 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:39:31 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon", false, 25, 5), _target(target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    *this = other;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned())
        throw AForm::FormAlreadySiged();
    if (executor.getGrade() > getRequiredExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
