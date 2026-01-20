/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:24:24 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/20 15:10:14 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(low)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
    if (grade < high)
        throw GradeTooHighException();
    if (grade > low)
        throw GradeTooLowException();
    
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (other._grade < high)
        throw GradeTooHighException();
    if (other._grade > low)
        throw GradeTooLowException();
        
    this->_grade = other._grade;
    
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    this->_grade--;
    if (this->_grade < high)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
    if (this->_grade > low)
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return RED "Grade too high!" RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return RED "Grade too low!" RESET;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << GREEN << other.getName() << RESET
       << ", bureaucrat grade "
       << YELLOW << other.getGrade() << RESET
       << std::endl;
    return os;
}
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << this->getName() << RESET
                  << " signed " << CYAN << form.getName() << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << this->getName() << RESET
                  << " couldn't sign " << CYAN << form.getName() << RESET
                  << " because " << e.what() << std::endl;
    }
}

