/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 13:56:46 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*::: CONSTRUCTORS :::*/
Animal::Animal(void) {

	std::cout << WHITE
				<< "Constructor: Generic Animal created"
				<< END_COLOR << std::endl;
	return ;
}

Animal::Animal(Animal const &copie) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: Animal copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Animal::~Animal(void) {

	std::cout << WHITE
				<< "Destructor: Animal destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Animal &Animal::operator=(Animal const &other) {

	this->type = other.type;
	std::cout << WHITE
				<< "Operator Overload = called for Animal"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void Animal::makeSound(void) const {

	std::cout << WHITE << "*** Something scary makes a sound ***" << END_COLOR << std::endl;
	return ;
}

std::string Animal::getType(void) const {

	return this->type;
}