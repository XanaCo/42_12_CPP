/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 16:30:37 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*::: CONSTRUCTORS :::*/

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(MIN_GRADE) {

	std::cout << GREEN
				<< "Constructor: Unknown Bureaucrat created"
				<< END_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {

	if (name.empty())
		throw NoName();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();

	std::cout << GREEN
			<< "Constructor: "
			<< _name
			<< " Bureaucrat created"
			<< END_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {

	std::cout << B_GREEN
				<< "Constructor: Bureaucrat copy created"
				<< END_COLOR << std::endl;
}

/*::: DESTRUCTORS :::*/

Bureaucrat::~Bureaucrat() {

	std::cout << RED
			<< "Destructor: "
			<< _name
			<< " Bureaucrat destroyed"
			<< END_COLOR << std::endl;
}

/*::: Operator Overloading ::: */

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {

	this->_grade = other.getGrade();

	std::cout << WHITE
				<< "Operator = called for "
				<< this->_name
				<< END_COLOR << std::endl;

	return *this;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other) {

	out << other.getName()
			<< ", bureaucrat grade "
			<< other.getGrade()
			<< ".";

	return out;
}

/*::: ACCESSORS :::*/

std::string	const &Bureaucrat::getName() const {

	return this->_name;
}

int const &Bureaucrat::getGrade() const {
	
	return this->_grade;
}

/*::: MEMBER FUNCTIONS :::*/

void Bureaucrat::bureaucratPromotion() {
	
	if (_grade == MAX_GRADE)
		throw GradeTooHighException();
	else
		_grade--;
}
void Bureaucrat::bureaucratDemotion() {

	if (_grade == MIN_GRADE)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form &form) {

	form.beSigned(*this);

	if (form.getIsSigned())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " because he hasn't the right grade." << std::endl;
}

/*::: EXCEPTIONS :::*/

const char *Bureaucrat::GradeTooHighException::what() const throw() {

	return YELLOW "Grade is too high" END_COLOR;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

	return YELLOW "Grade is too low" END_COLOR;
}

const char *Bureaucrat::NoName::what() const throw() {

	return YELLOW "You should name your Bureaucrat if you want to call this constructor" END_COLOR;
}