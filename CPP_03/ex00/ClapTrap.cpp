/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 14:00:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*::: CONSTRUCTORS :::*/

ClapTrap::ClapTrap(void) {

	_name = "Generic";
	_hit = 10;
	_energy = 10;
	_attack = 0;
	std::cout << WHITE
				<< "Constructor: Generic ClapTrap created"
				<< END_COLOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) {

	_name = name;
	_hit = 10;
	_energy = 10;
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

/*::: DESTRUCTORS :::*/

ClapTrap::~ClapTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " ClapTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {

	this->_name = other._name;
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void ClapTrap::attack(const std::string& target) {

	if (!_energy || !_hit)
	{
		std::cout << YELLOW
					<< "ClapTrap " << _name << " must be repaired ASAP, "
					<< target << " gets away!"
					<< END_COLOR << std::endl;
		return ;
	}
	_energy--;
	std::cout << RED
				<< "ClapTrap " << _name << " attacks " << target
				<< ", causing " << _attack << " points of damage!"
				<< END_COLOR << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (_hit > 0)
		_hit -= amount;
	if (_hit <= 0)
		_hit = 0;
	else if (_hit > 10)
		_hit = 10;
	std::cout << MAGENTA
			<< "ClapTrap " << _name << " takes " << amount
			<< " points of damage and has now " << _hit << " hit points left."
			<< END_COLOR << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (!_energy || !_hit)
	{
		std::cout << BLUE
					<< "ClapTrap " << _name
					<< " just lies on the ground looking at you, exhausted."
					<< END_COLOR << std::endl;
		return ;
	}
	_energy--;
	_hit += amount;
	if (_hit > 10)
		_hit = 10;
	std::cout << GREEN
				<< "ClapTrap " << _name
				<< " repaired himself and has now " 
				<< _hit << " hit points."
				<< END_COLOR << std::endl;
	return ;
}
