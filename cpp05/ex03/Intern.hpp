/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:05:58 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:06:00 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
    private:
        typedef AForm *(Intern::*FormCreator)(const std::string &target) const;

        AForm *createShrubberyForm(const std::string &target) const;
        AForm *createRobotomyForm(const std::string &target) const;
        AForm *createPresidentialPardonForm(const std::string &target) const;
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;

};

#endif
