/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/17 23:02:54 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*::: CONSTRUCTORS :::*/

Form::Form(void) : _name("Unknown") {

	std::cout << GREEN
				<< "Constructor: Unknown Form created"
				<< END_COLOR << std::endl;

	return ;
}


Form::Form(std::string const name, int gradeSign, int gradeExec) : _name(name) {

	std::string noname = this->getName();

	if (noname == "")
		throw NoName();
	if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
		throw GradeTooLowException();
	else
	{
		_gradeSign = gradeSign;
		_gradeExec = gradeExec; // initializer avant!
	}

	std::cout << GREEN
			<< "Constructor: "
			<< _name
			<< " Form created"
			<< END_COLOR << std::endl;

	return ;
}

Form::Form(Form const &copy) {

	*this = copy;
	std::cout << WHITE
				<< "Constructor: Form copy created"
				<< END_COLOR << std::endl;

	return ;
}

/*::: DESTRUCTORS :::*/

Form::~Form(void) {

	std::cout << RED
			<< "Destructor: "
			<< _name
			<< " Form created"
			<< END_COLOR << std::endl;

	return ;
}

/*::: Operator Overloading ::: */

Form &Form::operator=(Form const &other) {

	this->_grade = other.getGrade();
	std::cout << WHITE
				<< "Operator = called for "
				<< this->_name
				<< END_COLOR << std::endl;

	return *this;
}

std::ostream &operator<<(std::ostream &out, Form const &other) {

	out << other.getName()
			<< ", Form grade "
			<< other.getGrade()
			<< ".";
	return out;
}

/*::: MEMBER FUNCTIONS :::*/

std::string	const Form::getName(void) const {

	return this->_name;
}

int			Form::getGrade(void) const {
	
	return this->_grade;
}

void Form::FormPromotion(void) {
	
	if (_grade == MAX_GRADE)
		throw GradeTooHighException();
	else
		_grade--;

	return ;
}
void Form::FormDemotion(void) {

	if (_grade == MIN_GRADE)
		throw GradeTooLowException();
	else
		_grade++;

	return ;
}

const char *Form::GradeTooHighException::what(void) const throw() {

	return YELLOW "Grade is too high" END_COLOR;
}

const char *Form::GradeTooLowException::what(void) const throw() {

	return YELLOW "Grade is too low" END_COLOR;
}

const char *Form::NoName::what(void) const throw() {

	return YELLOW "You should name your Form if call this constructor" END_COLOR;
}