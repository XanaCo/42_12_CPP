/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 00:08:55 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*::: CONSTRUCTORS :::*/

Intern::Intern() {

	std::cout << GREEN
				<< "Constructor: Unknown Intern created"
				<< END_COLOR << std::endl;

	return ;
}

Intern::Intern(Intern const &copy) {

	(void)copy;
	std::cout << WHITE
				<< "Constructor: Intern copy created"
				<< END_COLOR << std::endl;

	return ;
}

/*::: DESTRUCTORS :::*/

Intern::~Intern() {

	std::cout << RED
			<< "Destructor: Intern destroyed"
			<< END_COLOR << std::endl;

	return ;
}

/*::: Operator Overloading ::: */

Intern &Intern::operator=(Intern const &other) {

	(void)other;
	std::cout << WHITE
				<< "Operator = called for Intern"
				<< END_COLOR << std::endl;

	return *this;
}

/*::: MEMBER FUNCTIONS :::*/


AForm *Intern::makeForm(std::string type, std::string target) {
	
	AForm *form;
	std::string types[] = {"Shrubbery", "Robotomy", "PresidentialPardon"};

	size_t it;
	for (it = 0; it < 3; it++)
	{
		if (type == types[it])
			break;
	}
	
	switch(it)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates a Shrubbery form" << std::endl;
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates a Robotomy form" << std::endl;
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates a PresidentialPardon form" << std::endl;
			break;
		default:
			form = NULL;
			std::cout << "Intern tries to create something but fails miserably" << std::endl;
			break;
	}
	
	return (form);	
}
