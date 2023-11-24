/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 17:57:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*::: CONSTRUCTORS :::*/

AForm::AForm() : _name("Unknown"), _gradeSign(MIN_GRADE), _gradeExec(MIN_GRADE) {

	this->_signed = false;
	
	std::cout << GREEN
				<< "Constructor: "
				<< this->_name 
				<< " created"
				<< END_COLOR << std::endl;

	return ;
}


AForm::AForm(std::string const name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {

	if (name.empty())
		throw NoName();
	if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
		throw GradeTooLowException();
	
	this->_signed = false;

	std::cout << GREEN
			<< "Constructor: "
			<< this->_name
			<< " created"
			<< END_COLOR << std::endl;

	return ;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {

	this->_signed = copy._signed;
	
	std::cout << WHITE
				<< "Constructor: "
				<< this->_name
				<< " copy created"
				<< END_COLOR << std::endl;

	return ;
}

/*::: DESTRUCTORS :::*/

AForm::~AForm() {

	std::cout << RED
			<< "Destructor: "
			<< this->_name
			<< " destroyed"
			<< END_COLOR << std::endl;

	return ;
}

/*::: Operator Overloading ::: */

std::ostream &operator<<(std::ostream &out, AForm const &other) {

	std::string answer;

	(other.getIsSigned())? answer = "YES" : answer = "NO";
		
	out << other.getName()
			<< ", gradeSign "
			<< other.getGradeSign()
			<< ", gradeExec "
			<< other.getGradeExec()
			<< ", signed "
			<< answer
			<< ".";

	return out;
}

/*::: ACCESSORS :::*/

std::string	const &AForm::getName() const {

	return this->_name;
}

int const &AForm::getGradeExec() const {
	
	return this->_gradeExec;
}

int const &AForm::getGradeSign() const {
	
	return this->_gradeSign;
}

bool AForm::getIsSigned() const {
	
	return this->_signed;
}

/*::: MEMBER FUNCTIONS :::*/

void AForm::beSigned(Bureaucrat const &someone) {
	
	if (someone.getGrade() > this->getGradeSign())
		throw GradeTooLowException();

	this->_signed = true;
}

/*::: EXCEPTIONS :::*/

const char *AForm::GradeTooHighException::what() const throw() {

	return YELLOW "Form Grade is too high" END_COLOR;
}

const char *AForm::GradeTooLowException::what() const throw() {

	return YELLOW "Form Grade is too low" END_COLOR;
}

const char *AForm::NoName::what() const throw() {

	return YELLOW "You should name your Form if call this constructor" END_COLOR;
}