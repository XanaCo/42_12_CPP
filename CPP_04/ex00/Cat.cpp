/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

Cat::Cat(void) {

	type = "Cat";
	std::cout << YELLOW
				<< "Constructor: Generic Cat created"
				<< END_COLOR << std::endl;
	return ;
}

Cat::Cat(Cat const &copie) {

	*this = copie;
	std::cout << YELLOW
				<< "Constructor: Cat copie created"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

Cat::~Cat(void) {

	std::cout << YELLOW
				<< "Destructor: Cat destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

Cat &Cat::operator=(Cat const &other) {

	this->type = other.type;
	std::cout << YELLOW
				<< "Operator Overload = called for Cat"
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void Cat::makeSound(void) const {

	std::cout << YELLOW << "MEOW" << END_COLOR << std::endl;
	return ;
}
