/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:27:33 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:45:03 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < HIGHEST_GRADE) 
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE) 
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat() : _name("muguveli") , _grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

const std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::gradeUp()
{
    if ((this->getGrade() - 1) < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}
void Bureaucrat::gradeDown()
{
    if ((this->getGrade() + 1) > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b) 
{
    os << b.getName() << ", Grade " << b.getGrade();
    return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is to low!");
}

Bureaucrat::~Bureaucrat() {}
