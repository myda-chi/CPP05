/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:30:49 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/07 16:35:50 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 1);
    AForm* yda = new ShrubberyCreationForm("Home");
    AForm* ydaa = new RobotomyRequestForm("Bender");
    AForm* ydaaa = new PresidentialPardonForm("Marvin");
    bob.signForm(*yda);
    bob.executeForm(*yda);
    bob.signForm(*ydaa);
    bob.executeForm(*ydaa);
    bob.signForm(*ydaaa);
    bob.executeForm(*ydaaa);
}