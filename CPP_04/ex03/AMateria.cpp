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

AMateria::AMateria(void) {

	std::cout << WHITE
				<< "Constructor: Generic AMateria created"
				<< END_COLOR << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) {

	//AFAIRE
	return ;
}

AMateria::AMateria(AMateria const &copie) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: AMateria copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

AMateria::~AMateria(void) {

	std::cout << WHITE
				<< "Destructor: AMateria destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

AMateria &AMateria::operator=(AMateria const &other) {

	std::cout << WHITE
				<< "Operator Overload = called for AMateria"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void AMateria::use(ICharacter& target) {

	//AFAIRE
	return ;
}
