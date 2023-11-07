/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

Dog::Dog(void) {

	type = "Dog";
	_brain = new Brain;
	std::cout << GREEN
				<< "Constructor: Dog created"
				<< END_COLOR << std::endl;
	return ;
}

Dog::Dog(Dog const &copie) {

	*this = copie;
	std::cout << GREEN
				<< "Constructor: Dog copie created"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

Dog::~Dog(void) {

	delete _brain;
	std::cout << GREEN
				<< "Destructor: Dog destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

Dog &Dog::operator=(Dog const &other) {

	this->type = other.type;
	std::cout << GREEN
				<< "Operator Overload = called for Dog"
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void Dog::makeSound(void) const {

	std::cout << GREEN << "WOOF" << END_COLOR << std::endl;
	return ;
}
