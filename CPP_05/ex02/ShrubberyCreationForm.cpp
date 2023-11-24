/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 17:48:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*::: CONSTRUCTORS :::*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {

	this->_target = target;

	std::cout << GREEN
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) {
	
	this->_target = copy._target;
	
	std::cout << WHITE
				<< "Constructor: "
				<< this->getName()
				<< " copy created"
				<< END_COLOR << std::endl;

	return ;
}


/*::: DESTRUCTORS :::*/

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << RED
			<< "Destructor: "
			<< this->getName()
			<< " destroyed"
			<< END_COLOR << std::endl;

	return ;
}

/*::: ACCESSORS :::*/

std::string const &ShrubberyCreationForm::getTarget() const {

	return this->_target;
}

/*::: MEMBER FUNCTIONS :::*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	
	
	// if !check executable fail
		//throw exception AForm


	std::ofstream out((this->_target + "_shrubbery").c_str());

	if (out.fail())
		throw ShrubberyException();
	
	


}

/*::: EXCEPTIONS :::*/

const char *ShrubberyCreationForm::ShrubberyException::what() const throw() {

	return YELLOW "ShrubberyForm Creation Failed" END_COLOR;
}