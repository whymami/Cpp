/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:33 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 15:55:36 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string _name;
		bool _isSigned;
		const int _requiredSignGrade;
		const int _requiredExecGrade;
	public:
		AForm();
		AForm (const std::string name, bool _isSigned, const int requiredSignGrade, const int requiredExecGrade);
		void beSigned(const Bureaucrat &bureaucrat);
        AForm &operator=(const AForm &other);
        AForm (const AForm &other);
		
		virtual void execute(const Bureaucrat &executor) const = 0;
		
		std::string getName() const;
		bool getIsSigned() const;
		int getRequiredSignGrade() const;
		int getRequiredExecGrade() const;
		virtual ~AForm();

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
std::ostream& operator<<(std::ostream &os, const AForm &f);
#endif
