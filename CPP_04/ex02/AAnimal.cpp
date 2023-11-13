/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 21:17:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*::: CONSTRUCTORS :::*/

AAnimal::AAnimal(void) {

	std::cout << WHITE
				<< "Constructor: Generic AAnimal created"
				<< END_COLOR << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &copie) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: AAnimal copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

AAnimal::~AAnimal(void) {

	std::cout << WHITE
				<< "Destructor: AAnimal destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

AAnimal &AAnimal::operator=(AAnimal const &other) {

	this->type = other.type;
	std::cout << WHITE
				<< "Operator Overload = called for AAnimal"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

std::string AAnimal::getType(void) const {

	return this->type;
}