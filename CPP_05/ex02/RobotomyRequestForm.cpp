/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 16:56:25 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::_robotomizations = 0;

/*::: CONSTRUCTORS :::*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {

	this->_target = target;

	std::cout << GREEN
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) {
	
	this->_target = copy._target;
	this->_robotomizations = copy._robotomizations;
	
	std::cout << B_GREEN
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;
}


/*::: DESTRUCTORS :::*/

RobotomyRequestForm::~RobotomyRequestForm() {

	std::cout << RED
			<< "Destructor: "
			<< this->getName()
			<< " destroyed"
			<< END_COLOR << std::endl;
}

/*::: ACCESSORS :::*/

std::string const &RobotomyRequestForm::getTarget() const {

	return this->_target;
}

/*::: MEMBER FUNCTIONS :::*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	this->checkExecution(executor);

	this->_robotomizations++;

	std::cout << WHITE << "* SEVERAL UNCONFORTABLE DRILLING NOISES *" << END_COLOR << std::endl;
	
	if (this->_robotomizations % 2)
		std::cout << GREEN << this->_target << " has been robotomized succesfully" << END_COLOR << std::endl;
	else
		std::cout << RED << "Robotomization failed for " << this->_target << END_COLOR << std::endl;
}

/*::: EXCEPTIONS :::*/

const char *RobotomyRequestForm::RobotomyException::what() const throw() {

	return YELLOW "RobotomyRequestForm Creation Failed" END_COLOR;
}