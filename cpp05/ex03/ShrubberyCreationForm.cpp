/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:19 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:48:57 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", false, 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default") {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    *this = other;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned())
        throw AForm::FormAlreadySiged();
    if (executor.getGrade() > getRequiredExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outFile;
    outFile.open((_target + "_shrubbery"), std::ios::out);
    if (!outFile)
        throw ShrubberyCreationForm::FileIsOpenException();


    outFile << "         ccee88oo\n"
               "      C8O8O8Q8PoOb o8oo\n"
               "   dOB69QO8PdUOpugoO9bD\n"
               "  CgggbU8OU qOp qOdoUOdcb\n"
               "    6OuU  /p u gcoUodpP\n"
               "       \\\\//  /douUP\n"
               "         \\\\////\n"
               "          |||/\n"
               "          ||| \n"
               "          ||| \n"
               "      .....|||.....\n";
    outFile.close();
}

const char *ShrubberyCreationForm::FileIsOpenException::what() const throw()
{
    return ("Failed to open file.");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}