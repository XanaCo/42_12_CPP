/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 14:34:47 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*::: CONSTRUCTORS :::*/

DiamondTrap::DiamondTrap(void) {

	ClapTrap::_name = "_clap_name";
	_hit = FragTrap::get_value(HIT);
	_max_hit = FragTrap::get_value(MAX_HIT);
	_energy = ScavTrap::get_value(ENERGY);
	_max_energy = ScavTrap::get_value(MAX_ENERGY);;
	_attack = FragTrap::get_value(ATTACK);
	std::cout << WHITE
				<< "Constructor: Generic DiamondTrap created"
				<< END_COLOR << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_name") {

	_name = name;
	_hit = FragTrap::get_value(HIT);
	_max_hit = FragTrap::get_value(MAX_HIT);
	_energy = ScavTrap::get_value(ENERGY);
	_max_energy = ScavTrap::get_value(MAX_ENERGY);;
	_attack = FragTrap::get_value(ATTACK);
	std::cout << WHITE
				<< "Constructor: " << _name << " DiamondTrap created"
				<< END_COLOR << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copie) {

	*this = copie;
	std::cout << WHITE
				<< "Constructor: " << _name << " DiamondTrap copie created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

DiamondTrap::~DiamondTrap(void) {

	std::cout << WHITE
				<< "Destructor: " << _name << " DiamondTrap destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {

	this->ClapTrap::_name = other.ClapTrap::_name;
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

/*::: MEMBER FUNCTIONS :::*/

void DiamondTrap::whoAmI(void) {

	std::cout << YELLOW
				<< "DiamondTrap name : " << this->_name
				<< " | ClapTrap name : " << this->ClapTrap::_name
				<< END_COLOR << std::endl;			
}

void	DiamondTrap::attack(const std::string& target) {

	ScavTrap::attack(target);
}
