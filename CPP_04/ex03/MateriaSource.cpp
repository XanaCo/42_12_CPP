/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:03:58 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*::: CONSTRUCTORS :::*/

MateriaSource::MateriaSource(void) {

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	std::cout << RED
				<< "Constructor: Generic MateriaSource created"
				<< END_COLOR << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {

	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	
	std::cout << RED
				<< "Constructor: MateriaSource copy created"
				<< END_COLOR << std::endl;
	return ;
}

/*::: DESTRUCTORS :::*/

MateriaSource::~MateriaSource(void) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	
	std::cout << RED
				<< "Destructor: MateriaSource destroyed"
				<< END_COLOR << std::endl;
	return ;
}

/*::: Operator Overloading ::: */

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
	
	std::cout << RED
				<< "Operator Overload = called for MateriaSource"
				<< END_COLOR << std::endl;
	return *this;
}

/*::: MEMBER FUNCTIONS :::*/

void MateriaSource::learnMateria(AMateria *materia) {

	int i;
	
	if (!materia)
	{
		std::cout << "Error: Cannot add a nonexistant Material" << std::endl;
		return ;
	}
	
	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
			break ;
	}
	if (i > 3)
		i = 0;

	this->_inventory[i] = materia;
	
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type) {

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}

	return 0;
}

