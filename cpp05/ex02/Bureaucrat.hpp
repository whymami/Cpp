/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:22:03 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 17:08:59 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include "AForm.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat(const Bureaucrat &other);
        const std::string getName() const;
        int getGrade() const;
        void gradeUp();
        void gradeDown();
        void signForm(AForm &form);
        void executeForm(const AForm &form) const;
        ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();

    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();

    };
};
std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif
