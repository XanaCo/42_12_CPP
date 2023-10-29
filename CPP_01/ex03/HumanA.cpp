/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 20:03:22 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"

/*CONSTRUCTORS*/

HumanA::HumanA(std::string name, Weapon &object) : _object(object)
{
	this->_name = name;
	return ;
}

/*DESTRUCTORS*/

HumanA::~HumanA(void)
{
	return ;
}

/*MEMBER FUNCTIONS*/

void HumanA::attack(void)
{
	std::cout << "\033[32;3m"
				<< this->_name
				<< " attacks with their "
				<< this->_object.getType()
				<< "\033[0m"
				<< std::endl;
}

void HumanA::setWeapon(Weapon &object)
{
	this->_object = object;
}
