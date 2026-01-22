/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:17:34 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/22 11:12:27 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << GREEN << " Default PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << GREEN << " Parameterized PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << GREEN << " PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << GREEN << " Copy PresidentialPardonForm constructor called" << RESET << std::endl;
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << GREEN << " PresidentialPardonForm assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
