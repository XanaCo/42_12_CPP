/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/15 14:44:23 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*::: CONSTRUCTORS :::*/

Ice::Ice(void) : AMateria("ice") {

	std::cout << WHITE
				<< "Constructor: Generic Ice created"
				<< END_COLOR << std::endl;
	return ;
}

Ice::Ice(Ice const &copy) : AMateria(copy.getType()) {

	std::cout << WHITE
				<< "Constructor: Ice copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Ice::~Ice(void) {

	std::cout << WHITE
				<< "Destructor: Ice destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Ice &Ice::operator=(Ice const &other) {

	(void)other;
	std::cout << WHITE
				<< "Operator Overload = called for Ice"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void Ice::use(ICharacter& target) {

	std::cout << WHITE
			<< "	* shoots an ice bolt at "
			<< target.getName()
			<< " *"
			<< END_COLOR << std::endl;
	return ;
}

AMateria* Ice::clone(void) const {

	AMateria *new_clone = new Ice(*this);
	return new_clone;
}