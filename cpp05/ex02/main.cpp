/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:08:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:40:35 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try 
    {
        Bureaucrat bureaucrat("Alice", 1);
        
        ShrubberyCreationForm shrubberyForm("home");
        shrubberyForm.beSigned(bureaucrat);
        bureaucrat.executeForm(shrubberyForm);

        RobotomyRequestForm robotomyForm("Bob");
        robotomyForm.beSigned(bureaucrat);
        bureaucrat.executeForm(robotomyForm);

        PresidentialPardonForm pardonForm("Charlie");
        pardonForm.beSigned(bureaucrat);
        bureaucrat.executeForm(pardonForm);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

