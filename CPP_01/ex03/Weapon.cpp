/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 19:17:10 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

/*CONSTRUCTORS*/

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string new_type)
{
	this->_type = new_type;
	return ;
}

/*DESTRUCTORS*/

Weapon::~Weapon(void)
{
	return ;
}

/*MEMBER FUNCTIONS*/

const std::string& Weapon::getType() const {
	
	return this->_type;
}

void Weapon::setType(std::string new_type) {
	
	this->_type = new_type;
	return ;
}

