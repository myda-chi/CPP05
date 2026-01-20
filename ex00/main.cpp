/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myda-chi <myda-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:00:54 by myda-chi          #+#    #+#             */
/*   Updated: 2026/01/20 15:02:54 by myda-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat *yda = new Bureaucrat("mydachi", 3);
        std::cout << *yda;
        yda->incrementGrade();
        std::cout << *yda;
        yda->incrementGrade();
        std::cout << *yda;
        delete yda;
    }
    catch (std::exception& b)
    {
        std::cout << b.what();
    }
}