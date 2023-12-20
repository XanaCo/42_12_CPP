/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/20 23:37:35 by ancolmen         ###   ########.fr       */
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
		throw SignatureDenied();
	else if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
		throw SignatureDenied();
	
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
	
	this->checkSignature(someone);

	this->_signed = true;
}

void AForm::checkSignature(Bureaucrat const &executor) const {

	if (this->getIsSigned())
		throw FormAlreadySigned();

	if (executor.getGrade() > this->getGradeSign())
		throw SignatureDenied();
	
}

void AForm::checkExecution(Bureaucrat const &executor) const {

	if (!this->getIsSigned())
		throw FormNotSigned();
	
	if (executor.getGrade() > this->getGradeExec())
		throw ExecutionDenied();
}

/*::: EXCEPTIONS :::*/

const char *AForm::NoName::what() const throw() {

	return YELLOW "Form name unknown" END_COLOR;
}

const char *AForm::FormNotSigned::what() const throw() {

	return YELLOW "Form should be signed before execution" END_COLOR;
}

const char *AForm::FormAlreadySigned::what() const throw() {

	return YELLOW "Form is already signed" END_COLOR;
}

const char *AForm::ExecutionDenied::what() const throw() {

	return YELLOW "Execution of the Form Denied" END_COLOR;
}

const char *AForm::SignatureDenied::what() const throw() {

	return YELLOW "Signature of the Form Denied" END_COLOR;
}