/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*::: CONSTRUCTORS :::*/
WrongAnimal::WrongAnimal(void) {

	type = "WrongAnimal";
	std::cout << RED
				<< "Constructor: Generic WrongAnimal created"
				<< END_COLOR << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copie) {

	*this = copie;
	std::cout << RED
				<< "Constructor: WrongAnimal copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

WrongAnimal::~WrongAnimal(void) {

	std::cout << RED
				<< "Destructor: WrongAnimal destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {

	this->type = other.type;
	std::cout << RED
				<< "Operator Overload = called for WrongAnimal"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void WrongAnimal::makeSound(void) const {

	std::cout << RED << "*** Something wrong and scary makes a dark sound ***" << END_COLOR << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const {

	return this->type;
}