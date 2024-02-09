/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/15 14:44:28 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*::: CONSTRUCTORS :::*/

Cure::Cure(void) : AMateria("cure") {

	std::cout << MAGENTA
				<< "Constructor: Generic Cure created"
				<< END_COLOR << std::endl;
	return ;
}

Cure::Cure(Cure const &copy) : AMateria(copy.getType()) {

	std::cout << MAGENTA
				<< "Constructor: Cure copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Cure::~Cure(void) {

	std::cout << MAGENTA
				<< "Destructor: Cure destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Cure &Cure::operator=(Cure const &other) {

	(void)other;
	std::cout << MAGENTA
				<< "Operator Overload = called for Cure"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void Cure::use(ICharacter& target) {

	std::cout << MAGENTA
			<< "	* heals "
			<< target.getName()
			<< "'s wounds *"
			<< END_COLOR << std::endl;
	return ;
}

AMateria* Cure::clone(void) const {

	AMateria *new_clone = new Cure(*this);
	return new_clone;
}