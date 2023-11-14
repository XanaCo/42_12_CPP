/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:57 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*::: CONSTRUCTORS :::*/

Cat::Cat(void) {

	type = "Cat";
	_catBrain = new Brain;
	std::cout << YELLOW
				<< "Constructor: Generic Cat created"
				<< END_COLOR << std::endl;
	return ;
}

Cat::Cat(Cat const &copy) {

	*this = copy;
	_catBrain = new Brain;
	std::cout << YELLOW
				<< "Constructor: Cat copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Cat::~Cat(void) {

	delete _catBrain;
	std::cout << YELLOW
				<< "Destructor: Cat destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Cat &Cat::operator=(Cat const &other) {

	this->type = other.type;
	for (int i = 0; i < IDEAS; i++)
	{
		std::string idea = (other.getCatBrain())->getIdea(i);
		(this->_catBrain)->setIdea(idea, i);
	}
	std::cout << YELLOW
				<< "Operator Overload = called for Cat"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void Cat::makeSound(void) const {

	std::cout << YELLOW << "MEOW" << END_COLOR << std::endl;
	return ;
}

void Cat::setIdea(std::string idea, int index) {
	
	this->_catBrain->setIdea(idea, index);
	return ;
}

Brain *Cat::getCatBrain(void) const {
	
	return this->_catBrain;
}