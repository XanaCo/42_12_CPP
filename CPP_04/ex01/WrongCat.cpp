/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:57 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*::: CONSTRUCTORS :::*/

WrongCat::WrongCat(void) {

	type = "WrongCat";
	std::cout << MAGENTA
				<< "Constructor: Generic WrongCat created"
				<< END_COLOR << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &copy) {

	*this = copy;
	std::cout << MAGENTA
				<< "Constructor: WrongCat copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

WrongCat::~WrongCat(void) {

	std::cout << MAGENTA
				<< "Destructor: WrongCat destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

WrongCat &WrongCat::operator=(WrongCat const &other) {

	this->type = other.type;
	std::cout << MAGENTA
				<< "Operator Overload = called for WrongCat"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void WrongCat::makeSound(void) const {

	std::cout << MAGENTA << "MEOW" << END_COLOR << std::endl;
	return ;
}
