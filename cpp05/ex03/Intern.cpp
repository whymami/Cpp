/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:05:41 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:42:01 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) 
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other) 
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyForm(const std::string &target) const 
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) const 
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const 
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    FormCreator formCreators[] = 
    {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) 
        if (formNames[i] == formName) 
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    std::cout << "Error: Form " << formName << " not found." << std::endl;
    return NULL;
}
