/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:05 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*::: CONSTRUCTORS :::*/

Form::Form() : _name("Unknown"), _gradeSign(MIN_GRADE), _gradeExec(MIN_GRADE) {

	this->_signed = false;
	
	std::cout << GREEN
				<< "Constructor: Unknown Form created"
				<< END_COLOR << std::endl;
}

Form::Form(std::string const name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {

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
			<< " Form created"
			<< END_COLOR << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {

	this->_signed = copy._signed;
	
	std::cout << B_GREEN
				<< "Constructor: Form copy created"
				<< END_COLOR << std::endl;
}

/*::: DESTRUCTORS :::*/

Form::~Form() {

	std::cout << RED
			<< "Destructor: "
			<< _name
			<< " Form destroyed"
			<< END_COLOR << std::endl;
}

/*::: Operator Overloading ::: */

std::ostream &operator<<(std::ostream &out, Form const &other) {

	std::string answer;

	(other.getIsSigned())? answer = "YES" : answer = "NO";
		
	out << other.getName()
			<< ", Form gradeSign "
			<< other.getGradeSign()
			<< ", Form gradeExec "
			<< other.getGradeExec()
			<< ", Form signed "
			<< answer
			<< ".";

	return out;
}

/*::: ACCESSORS :::*/

std::string	const &Form::getName() const {

	return this->_name;
}

int const &Form::getGradeExec() const {
	
	return this->_gradeExec;
}

int const &Form::getGradeSign() const {
	
	return this->_gradeSign;
}

bool Form::getIsSigned() const {
	
	return this->_signed;
}

/*::: MEMBER FUNCTIONS :::*/

void Form::beSigned(Bureaucrat const &someone) {
	
	if (someone.getGrade() > this->getGradeSign())
		throw GradeTooLowException();

	this->_signed = true;
}

/*::: EXCEPTIONS :::*/

const char *Form::GradeTooHighException::what() const throw() {

	return YELLOW "Form Grade is too high" END_COLOR;
}

const char *Form::GradeTooLowException::what() const throw() {

	return YELLOW "Form Grade is too low" END_COLOR;
}

const char *Form::NoName::what() const throw() {

	return YELLOW "You should name your Form if call this constructor" END_COLOR;
}