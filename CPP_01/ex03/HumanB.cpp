/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 19:53:32 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

/*CONSTRUCTORS*/

HumanB::HumanB(std::string name)
{
	this->_name = name;
	return ;
}

/*DESTRUCTORS*/

HumanB::~HumanB(void)
{
	return ;
}

/*MEMBER FUNCTIONS*/

void HumanB::attack(void)
{
	std::cout << "\033[33;3m"
				<< this->_name
				<< " attacks with their "
				<< this->_object->getType()
				<< "\033[0m"
				<< std::endl;
}

void HumanB::setWeapon(Weapon &object)
{
	this->_object = &object;
}