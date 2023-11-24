/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 15:52:39 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*::: CONSTRUCTORS :::*/

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(MIN_GRADE) {

	std::cout << GREEN
				<< "Constructor: Unknown Bureaucrat created"
				<< END_COLOR << std::endl;

	return ;
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

	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {

	std::cout << WHITE
				<< "Constructor: Bureaucrat copy created"
				<< END_COLOR << std::endl;

	return ;
}

/*::: DESTRUCTORS :::*/

Bureaucrat::~Bureaucrat() {

	std::cout << RED
			<< "Destructor: "
			<< _name
			<< " Bureaucrat destroyed"
			<< END_COLOR << std::endl;

	return ;
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

/*::: MEMBER FUNCTIONS :::*/

std::string	const &Bureaucrat::getName() const {

	return this->_name;
}

int const &Bureaucrat::getGrade() const {
	
	return this->_grade;
}

void Bureaucrat::bureaucratPromotion() {
	
	if (_grade == MAX_GRADE)
		throw GradeTooHighException();
	else
		_grade--;

	return ;
}
void Bureaucrat::bureaucratDemotion() {

	if (_grade == MIN_GRADE)
		throw GradeTooLowException();
	else
		_grade++;

	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {

	return YELLOW "Grade is too high" END_COLOR;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {

	return YELLOW "Grade is too low" END_COLOR;
}

const char *Bureaucrat::NoName::what() const throw() {

	return YELLOW "You should name your Bureaucrat if you want to call this constructor" END_COLOR;
}