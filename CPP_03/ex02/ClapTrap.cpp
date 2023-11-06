/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                     Constructors                                           */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) {

	_name = "Generic";
	_hit = 10;
	_max_hit = 10;
	_energy = 10;
	_max_energy = 10;
	_attack = 0;
	std::cout << WHITE
				<< "Constructor: Generic ClapTrap created"
				<< END_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) {

	_name = name;
	_hit = 10;
	_max_hit = 10;
	_energy = 10;
	_max_energy = 10;
	_attack = 0;
	std::cout << WHITE
				<< "Constructor: " << _name << " ClapTrap created"
				<< END_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copie) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: " << _name << " ClapTrap copie created"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Destructors                                            */
/* ************************************************************************** */

ClapTrap::~ClapTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " ClapTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Operator Overload                                      */
/* ************************************************************************** */

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {

	this->_name = other._name;
	this->_hit = other._hit;
	this->_max_hit = other._max_energy;
	this->_energy = other._energy;
	this->_max_energy = other._max_energy;
	this->_attack = other._attack;
	std::cout << WHITE
				<< "Operator Overload: called for ClapTrap " << _name
				<< END_COLOR << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                     Members                                                */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target) {

	if (!_energy || !_hit)
	{
		std::cout << YELLOW
					<< _name << " must be repaired ASAP, "
					<< target << " gets away!"
					<< END_COLOR << std::endl;
		return ;
	}
	_energy--;
	std::cout << RED
				<< _name << " attacks " << target
				<< ", causing " << _attack << " points of damage!"
				<< END_COLOR << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (_hit > 0)
		_hit -= amount;
	if (_hit <= 0)
		_hit = 0;
	else if (_hit > _max_hit)
		_hit = _max_hit;
	std::cout << MAGENTA
			<< _name << " takes " << amount
			<< " points of damage and has now " << _hit << " hit points left."
			<< END_COLOR << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (!_energy || !_hit)
	{
		std::cout << BLUE
					<< _name
					<< " just lies on the ground looking at you, exhausted."
					<< END_COLOR << std::endl;
		return ;
	}
	_energy--;
	_hit += amount;
	if (_hit > _max_hit)
		_hit = _max_hit;
	std::cout << GREEN
				<< _name
				<< " repaired himself and has now " 
				<< _hit << " hit points."
				<< END_COLOR << std::endl;
	return ;
}

void ClapTrap::display_info(void) const{

	std::cout << std::endl << _name
				<< " INFOS : " << std::endl
				<< " - Hit points : " << _hit << std::endl
				<< " - Energy points : " << _energy << std::endl
				<< " - Attack damage : " << _attack << std::endl
				<< std::endl;
	return ;
}

