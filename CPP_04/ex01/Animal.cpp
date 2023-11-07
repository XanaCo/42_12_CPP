/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

Animal::~Animal(void) {

	std::cout << WHITE
				<< "Destructor: Animal destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

Animal &Animal::operator=(Animal const &other) {

	this->type = other.type;
	std::cout << WHITE
				<< "Operator Overload = called for Animal"
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void Animal::makeSound(void) const {

	std::cout << WHITE << "*** Something scary makes a sound ***" << END_COLOR << std::endl;
	return ;
}

std::string Animal::getType(void) const {

	return this->type;
}