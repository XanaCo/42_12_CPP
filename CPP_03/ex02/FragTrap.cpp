/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:10:14 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap::ClapTrap() {

	_name = "Generic";
	_hit = 100;
	_max_hit = 100;
	_energy = 100;
	_max_energy = 100;
	_attack = 30;
	std::cout << WHITE
				<< "Constructor: Generic FragTrap created"
				<< END_COLOR << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name) {

	_name = name;
	_hit = 100;
	_max_hit = 100;
	_energy = 100;
	_max_energy = 100;
	_attack = 30;
	std::cout << WHITE
				<< "Constructor: " << _name << " FragTrap created"
				<< END_COLOR << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &copie) : ClapTrap::ClapTrap(copie._name) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: " << _name << " FragTrap copie created"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

FragTrap::~FragTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " FragTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

FragTrap &FragTrap::operator=(FragTrap const &other) {

	this->_name = other._name;
	this->_hit = other._hit;
	this->_max_hit = other._max_hit;
	this->_energy = other._energy;
	this->_max_energy = other._max_energy;
	this->_attack = other._attack;
	std::cout << WHITE
				<< "Operator Overload: called for FragTrap " << _name
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void FragTrap::highFivesGuys(void) {

	std::cout << BLUE
				<< "FragTrap " << _name
				<< " request a High Five!"
				<< END_COLOR << std::endl;
				
}
