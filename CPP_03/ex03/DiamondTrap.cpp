/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:46:43 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) {

	this->ClapTrap::_name = "Generic";
	this->_hit = this->FlagTrap::get_value(HIT);
	_max_hit = 100;
	_energy = 100;
	_max_energy = 100;
	_attack = 30;
	std::cout << WHITE
				<< "Constructor: Generic DiamondTrap created"
				<< END_COLOR << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name) {

	_name = name;
	_hit = 100;
	_max_hit = 100;
	_energy = 100;
	_max_energy = 100;
	_attack = 30;
	std::cout << WHITE
				<< "Constructor: " << _name << " DiamondTrap created"
				<< END_COLOR << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copie) : ClapTrap::ClapTrap(copie._name) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: " << _name << " DiamondTrap copie created"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

DiamondTrap::~DiamondTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " DiamondTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {

	this->_name = other._name;
	this->_hit = other._hit;
	this->_max_hit = other._max_hit;
	this->_energy = other._energy;
	this->_max_energy = other._max_energy;
	this->_attack = other._attack;
	std::cout << WHITE
				<< "Operator Overload: called for DiamondTrap " << _name
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void DiamondTrap::whoAmI(void) {

	std::cout << BLUE
				<< "DiamondTrap : " << _name
				<< "| ClapTrap : " << ClapTrap::ClapTrap._name
				<< END_COLOR << std::endl;
				
}

int DiamondTrap::get_value(int index) {

	if (index == HIT)
		return this->_hit;
				
}
