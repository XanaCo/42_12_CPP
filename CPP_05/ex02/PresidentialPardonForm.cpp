/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 16:56:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*::: CONSTRUCTORS :::*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {

	this->_target = target;

	std::cout << GREEN
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) {
	
	this->_target = copy._target;
	
	std::cout << B_GREEN
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;
}


/*::: DESTRUCTORS :::*/

PresidentialPardonForm::~PresidentialPardonForm() {

	std::cout << RED
			<< "Destructor: "
			<< this->getName()
			<< " destroyed"
			<< END_COLOR << std::endl;
}

/*::: ACCESSORS :::*/

std::string const &PresidentialPardonForm::getTarget() const {

	return this->_target;
}

/*::: MEMBER FUNCTIONS :::*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	this->checkExecution(executor);

	std::cout << BLUE << this->_target << " has been pardoned by Zaphod Beeblebrox" << END_COLOR << std::endl;
}

/*::: EXCEPTIONS :::*/

const char *PresidentialPardonForm::RobotomyException::what() const throw() {

	return YELLOW "PresidentialPardonForm Creation Failed" END_COLOR;
}