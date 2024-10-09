/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:08:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:23:47 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureaucrat boss("mami", 1);
        
        Intern someRandomIntern;

        AForm *shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (shrubberyForm) 
        {
            std::cout << *shrubberyForm << std::endl;
            boss.signForm(*shrubberyForm);
            boss.executeForm(*shrubberyForm);
            delete shrubberyForm;
        }
        AForm *robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robotomyForm) 
        {
            std::cout << *robotomyForm << std::endl;
            boss.signForm(*robotomyForm);
            boss.executeForm(*robotomyForm);
            delete robotomyForm;
        }
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (pardonForm) 
        {
            std::cout << *pardonForm << std::endl;
            boss.signForm(*pardonForm);
            boss.executeForm(*pardonForm);
            delete pardonForm;
        }

        AForm *invalidForm = someRandomIntern.makeForm("invalid form", "Unknown");
        if (invalidForm)
            delete invalidForm;
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
