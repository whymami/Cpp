/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:10 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/09 19:48:29 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        void execute(const Bureaucrat &executor) const;
        ~PresidentialPardonForm();
};

#endif
