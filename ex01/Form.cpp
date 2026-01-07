/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:38:28 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/07 14:36:49 by myda-chi         ###   ########.fr       */
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
    std::cout << _name << " created." << std::endl;
}
Form::~Form()
{
    std::cout << _name << " destroyed." << std::endl;
}
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "copy of form created." << std::endl;
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

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if(Bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_isSigned = true;
        std::cout <<Bureaucrat.getName() << " signed " << this->_name << std::endl; 
    }
    else
    {
        throw GradeTooLowException();
        std::cout <<Bureaucrat.getName() << " couldn't sign " << this->_name << " because his grade is too low." << std::endl;  
    }
}

const char* Form::GradeTooHighException::what() const noexcept
{
    return "Form Exception: Grade is too high.";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Form Exception: Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeToSign()
       << ", Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}