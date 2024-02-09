/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 13:59:26 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*::: CONSTRUCTORS :::*/

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap() {

	_hit = 100;
	_max_hit = 100;
	_energy = 50;
	_max_energy = 50;
	_attack = 20;
	std::cout << WHITE
				<< "Constructor: Generic ScavTrap created"
				<< END_COLOR << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name) {

	_name = name;
	_hit = 100;
	_max_hit = 100;
	_energy = 50;
	_max_energy = 50;
	_attack = 20;
	std::cout << WHITE
				<< "Constructor: " << _name << " ScavTrap created"
				<< END_COLOR << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &copie) : ClapTrap::ClapTrap(copie._name) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: " << _name << " ScavTrap copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

ScavTrap::~ScavTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " ScavTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {

	this->_name = other._name;
	this->_hit = other._hit;
	this->_max_hit = other._max_hit;
	this->_energy = other._energy;
	this->_max_energy = other._max_energy;
	this->_attack = other._attack;
	std::cout << WHITE
				<< "Operator Overload: called for ScavTrap " << _name
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void ScavTrap::attack(const std::string& target) {

	if (!_energy || !_hit)
	{
		std::cout << YELLOW
					<< _name << " must be also repaired ASAP, "
					<< target << " gets away!"
					<< END_COLOR << std::endl;
		return ;
	}
	_energy--;
	std::cout << RED
				<< _name << " attacks again " << target
				<< ", causing " << _attack << " points of damage!"
				<< END_COLOR << std::endl;
	return ;
}

void ScavTrap::guardGate() {

	std::cout << BLUE
				<< "ScavTrap " << _name
				<< " is now in Gate Keeper Mode."
				<< END_COLOR << std::endl;
	return ;
}
