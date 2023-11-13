/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 13:56:46 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*::: CONSTRUCTORS :::*/
Brain::Brain(void) {

	std::cout << BLUE
				<< "Constructor: Generic Brain created"
				<< END_COLOR << std::endl;
	return ;
}

Brain::Brain(Brain const &copie) {

	*this = copie;
	std::cout << BLUE
				<< "Constructor: Brain copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

Brain::~Brain(void) {

	std::cout << BLUE
				<< "Destructor: Brain destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Brain &Brain::operator=(Brain const &other) {

	*this->_ideas = *other._ideas;
	std::cout << BLUE
				<< "Operator Overload = called for Brain"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/


