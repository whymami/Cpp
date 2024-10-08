/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:33 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 13:52:37 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _requiredSignGrade;
		const int _requiredExecGrade;
	public:
		Form();
		Form (const std::string name, bool _isSigned, const int requiredSignGrade, const int requiredExecGrade);
		void beSigned(const Bureaucrat &bureaucrat);
        Form &operator=(const Form &other);
        Form (const Form &other);

		std::string getName() const;
		bool getIsSigned() const;
		int getRequiredSignGrade() const;
		int getRequiredExecGrade() const;
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormAlreadySiged : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &os, const Form &f);
#endif
