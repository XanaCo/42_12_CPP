/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:57 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*::: CONSTRUCTORS :::*/

Dog::Dog(void) {

	type = "Dog";
	_dogBrain = new Brain;
	std::cout << GREEN
				<< "Constructor: Dog created"
				<< END_COLOR << std::endl;
	return ;
}

Dog::Dog(Dog const &copy) {

	_dogBrain = new Brain;
	*this = copy;
	std::cout << GREEN
				<< "Constructor: Dog copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Dog::~Dog(void) {

	delete _dogBrain;
	std::cout << GREEN
				<< "Destructor: Dog destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Dog &Dog::operator=(Dog const &other) {

	this->type = other.type;
	for (int i = 0; i < IDEAS; i++)
	{
		std::string idea = (other.getDogBrain())->getIdea(i);
		(this->_dogBrain)->setIdea(idea, i);
	}
	std::cout << GREEN
				<< "Operator Overload = called for Dog"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void Dog::makeSound(void) const {

	std::cout << GREEN << "WOOF" << END_COLOR << std::endl;
	return ;
}

void Dog::setIdea(std::string idea, int index) {
	
	this->_dogBrain->setIdea(idea, index);
	return ;
}

Brain *Dog::getDogBrain(void) const {
	
	return this->_dogBrain;
}
