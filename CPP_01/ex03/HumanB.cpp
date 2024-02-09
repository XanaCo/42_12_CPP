/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 20:09:05 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*CONSTRUCTORS*/

HumanB::HumanB(std::string name) {

	this->_name = name;
	return ;
}

/*DESTRUCTORS*/

HumanB::~HumanB(void) {

	return ;
}

/*MEMBERS*/

void HumanB::attack(void) {

	std::cout << "\033[33;3m"
				<< this->_name
				<< " attacks with their "
				<< this->_object->getType()
				<< "\033[0m"
				<< std::endl;
}

void HumanB::setWeapon(Weapon &object) {

	this->_object = &object;
}