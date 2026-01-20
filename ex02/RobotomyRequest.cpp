/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:21:00 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/20 17:13:13 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << GREEN << " Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << GREEN << " Parameterized RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << GREEN << " RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << GREEN << " Copy RobotomyRequestForm constructor called" << RESET << std::endl;
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << GREEN << " RobotomyRequestForm assignment operator called" << RESET<< std::endl;
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout <<RED <<"Bzzzzzz... Vrrrrrr... *drilling noises*" << RESET << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << _target <<GREEN " has been robotomized successfully." << std::endl;
    else
        std::cout << RED << "The robotomy on " << _target << " failed." << RESET << std::endl;
}

