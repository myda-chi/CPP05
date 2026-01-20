/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:28:27 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/20 17:19:10 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout <<GREEN << " Default ShrubberyCreationForm constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm
(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << GREEN << " Parameterized ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << GREEN << " ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << GREEN << " Copy ShrubberyCreationForm constructor called" << RESET << std::endl;
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << GREEN << " ShrubberyCreationForm assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile)
    {
        std::cerr <<RED << "Error creating file: " << filename << std::endl;
        return;
    }
    
outfile << "    *" << std::endl
        << "   ***" << std::endl
        << "  *****" << std::endl
        << " *******" << std::endl
        << "*********" << std::endl
        << "    |" << std::endl
        << "    |" << std::endl;

    outfile.close();
    std::cout <<GREEN << "Shrubbery created in file: " << filename << std::endl;
}