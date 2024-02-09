/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:24 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*::: CONSTRUCTORS :::*/

Intern::Intern() {

	std::cout << GREEN
				<< "Constructor: Unknown Intern created"
				<< END_COLOR << std::endl;
}

Intern::Intern(Intern const &copy) {

	(void)copy;
	std::cout << B_GREEN
				<< "Constructor: Intern copy created"
				<< END_COLOR << std::endl;
}

/*::: DESTRUCTORS :::*/

Intern::~Intern() {

	std::cout << RED
			<< "Destructor: Intern destroyed"
			<< END_COLOR << std::endl;
}

/*::: Operator Overloading ::: */

Intern &Intern::operator=(Intern const &other) {

	(void)other;
	std::cout << B_GREEN
				<< "Operator = called for Intern"
				<< END_COLOR << std::endl;

	return *this;
}

/*::: MEMBER FUNCTIONS :::*/


AForm *Intern::makeForm(std::string type, std::string target) {
	
	AForm *form;
	std::string types[3] = {"Shrubbery", "Robotomy", "PresidentialPardon"};

	int it;
	for (it = 0; it < 3; it++)
	{
		if (type == types[it])
			break;
	}
	
	switch(it)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			std::cout << B_GREEN << "	Intern creates a Shrubbery form" << END_COLOR << std::endl;
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << B_BLUE << "	Intern creates a Robotomy form" << END_COLOR << std::endl;
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			std::cout << B_MAGENTA << "	Intern creates a PresidentialPardon form" << END_COLOR << std::endl;
			break;
		default:
			form = NULL;
			std::cout << B_RED << "	Intern tries to create something but fails miserably" << END_COLOR << std::endl;
			break;
	}
	
	return (form);
}
