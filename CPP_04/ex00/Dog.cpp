/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 13:56:46 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*::: CONSTRUCTORS :::*/
Dog::Dog(void) {

	type = "Dog";
	std::cout << GREEN
				<< "Constructor: Dog created"
				<< END_COLOR << std::endl;
	return ;
}

Dog::Dog(Dog const &copie) {

	*this = copie;
	std::cout << GREEN
				<< "Constructor: Dog copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Dog::~Dog(void) {

	std::cout << GREEN
				<< "Destructor: Dog destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Dog &Dog::operator=(Dog const &other) {

	this->type = other.type;
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
