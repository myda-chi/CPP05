/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:02:14 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/22 13:40:57 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		AForm* rrf;
		AForm* ppf;
		AForm* scf;
		AForm* unknown;
		Intern someRandomIntern;
		Bureaucrat	a("yda", 20);
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		unknown = someRandomIntern.makeForm("unknown form", "Bender");
		rrf->execute(a);
		ppf->execute(a);
		scf->execute(a);
		unknown->execute(a);
		delete rrf;
		delete ppf;
		delete scf;
		delete unknown;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
