/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:43 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:37:25 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy Request",false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm() : _target("Default") {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    *this = other;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned())
        throw AForm::FormAlreadySiged();
    if (executor.getGrade() > getRequiredExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    srand(time(0));
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << _target << " failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}