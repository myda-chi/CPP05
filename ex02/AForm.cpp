/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:22 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/07 17:03:39 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("name"), _isSigned(false), _gradeToExecute(150), _gradeToSign(150)
{
}
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}   

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToExecute <= 0|| gradeToSign <= 0)
        throw GradeTooHighException();
    else if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "copy of AForm created." << std::endl;
}
AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm assignment operator called." << std::endl;
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}
const char* AForm::GradeTooHighException::what() const noexcept
{
    return "AForm Exception: Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "AForm Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "AForm Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return os;
}

