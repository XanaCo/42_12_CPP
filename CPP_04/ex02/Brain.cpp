/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 21:17:04 by ancolmen         ###   ########.fr       */
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

	for (int i = 0; i < IDEAS; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << BLUE
				<< "Operator Overload = called for Brain"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

std::string Brain::getIdea(int index) const {

	if (index < 0 || index > IDEAS)
		return NULL;
	return this->_ideas[index];
}

void Brain::setIdea(std::string &idea, int index) {

	if (index < 0 || index > IDEAS)
		return ;
	this->_ideas[index] = idea;
	return ;
}


