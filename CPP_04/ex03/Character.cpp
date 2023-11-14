/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:10:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*::: CONSTRUCTORS :::*/

Character::Character(void) : _name("Generic") {

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	std::cout << YELLOW
				<< "Constructor: Generic Character created"
				<< END_COLOR << std::endl;
	return ;
}

Character::Character(std::string name) : _name(name) {

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	std::cout << YELLOW
				<< "Constructor: "
				<< _name
				<< " Character created"
				<< END_COLOR << std::endl;
	return ;
}

Character::Character(Character const &copy) {

	this->_name = copy._name;
	
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}

	std::cout << YELLOW
				<< "Constructor: Character copy created"
				<< END_COLOR << std::endl;

	return ;
}

/*::: DESTRUCTORS :::*/

Character::~Character(void) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	
	std::cout << YELLOW
				<< "Destructor: Character destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

Character &Character::operator=(Character const &other) {
	
	this->_name = other._name;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}

	std::cout << YELLOW
				<< "Operator Overload = called for Character"
				<< END_COLOR << std::endl;

	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

std::string const &Character::getName(void) const {

	return this->_name;
}

void Character::equip(AMateria *m) {

	int i;
	
	if (!m)
	{
		std::cout << "Error: Cannot add a nonexistant Materia" << std::endl;
		return ;
	}
	
	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
			break ;
	}
	if (i > 3)
	{
		std::cout << "Error: You should unequip something first" << std::endl;
		return ;
	}

	this->_inventory[i] = m;
	
	return ;
}

void Character::unequip(int idx) {

	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: Index is out of reach" << std::endl;	
		return ;
	}
	this->_inventory[idx] = NULL;

	return ;
}
	
void Character::use(int idx, ICharacter &target) {

	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: Index is out of reach" << std::endl;	
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << "* No item at index [ " << idx << " ] *" << std::endl;	
		return ;
	}
	
	this->_inventory[idx]->use(target);

	return ;
}
