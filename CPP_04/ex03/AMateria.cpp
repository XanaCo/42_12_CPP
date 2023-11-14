/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 21:17:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*::: CONSTRUCTORS :::*/

AMateria::AMateria(void) : _type("Generic") {

	std::cout << GREEN
				<< "Constructor: Generic AMateria created"
				<< END_COLOR << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	
	std::cout << GREEN
				<< "Constructor: AMateria "
				<< _type
				<< " created"
				<< END_COLOR << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &copy) {

	*this = copy;
	std::cout << GREEN
				<< "Constructor: AMateria copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

AMateria::~AMateria(void) {

	std::cout << GREEN
				<< "Destructor: AMateria destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

AMateria &AMateria::operator=(AMateria const &other) {

	_type = other.getType();
	std::cout << GREEN
				<< "Operator Overload = called for AMateria"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void AMateria::use(ICharacter& target) {

	std::cout << GREEN
				<< "* "
				<< _type
				<< " enters "
				<< target.getName()
				<< " body *"
				<< END_COLOR << std::endl;
	return ;
}

std::string const & AMateria::getType(void) const {

	return this->_type;
}