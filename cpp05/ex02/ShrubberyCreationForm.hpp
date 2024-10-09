/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:04:09 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:41:10 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        void execute(const Bureaucrat &executor) const;
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ShrubberyCreationForm (const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

    class FileIsOpenException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif
