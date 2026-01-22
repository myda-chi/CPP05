/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:01:53 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/22 11:09:51 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << YELLOW "Ïntern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout <<GREEN "Intern copy constructor called" << RESET << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout <<GREEN "Intern assignment operator called" << RESET << std::endl;
    (void)other;
    return *this;
}
Intern::~Intern() 
{
    std::cout << RED "Intern destructor called" << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i = 0;
    while (i < 3 && name != formNames[i])
        i++;

    switch(i) {
        case 0: 
            std::cout <<GREEN "Intern creates ShrubberyCreationForm\n" << RESET; 
            return new ShrubberyCreationForm(target);
        case 1: 
            std::cout <<GREEN "Intern creates RobotomyRequestForm\n" << RESET; 
            return new RobotomyRequestForm(target);
        case 2: 
            std::cout <<GREEN "Intern creates PresidentialPardonForm\n" << RESET; 
            return new PresidentialPardonForm(target);
        default:
            std::cout <<RED "Intern could not create \"" << name << "\"\n" << RESET;
            return NULL;
    }
}
