/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:38:28 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/22 11:16:37 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("name"), _isSigned(false), _gradeToExecute(150), _gradeToSign(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    
    std::cout << CYAN << _name << RESET << " created." << std::endl;
}

Form::~Form()
{
    std::cout << CYAN << _name << RESET << " destroyed." << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy of form " << CYAN << _name << RESET << " created." << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form assignment operator called." << std::endl;
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_isSigned = true;
    }
    else
    {
        std::cout << RED << bureaucrat.getName() << RESET
                  << " couldn't sign " << CYAN << this->_name << RESET
                  << " because grade is too low." << std::endl;  
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const noexcept
{
    return RED "Form Exception: Grade is too high." RESET;
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return RED "Form Exception: Grade is too low." RESET;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << CYAN << "Form Name: " << form.getName() << RESET
        << ", Signed: " << (form.getIsSigned() ? GREEN "Yes" RESET : RED "No" RESET)
       << ", Grade Required to Sign: " << YELLOW << form.getGradeToSign() << RESET
       << ", Grade Required to Execute: " << YELLOW << form.getGradeToExecute() << RESET;
    return os;
}
