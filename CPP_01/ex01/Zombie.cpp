/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 17:40:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

/*CONSTRUCTORS*/

Zombie::Zombie(void)
{
	std::cout << "\033[32;3mConstructor: Default Zombie created\033[0m"
				<< std::endl;
	return ;
}

/*DESTRUCTORS*/

Zombie::~Zombie(void)
{
	std::cout << "\033[91;3mDestructor: Zombie "
				<< this->_name
				<< " destroyed\033[0m"
				<< std::endl;
	return ;
}

/*MEMBER FUNCTIONS*/

void Zombie::annouce(void)
{
	std::cout << "\033[94;1m"
				<< this->_name 
				<< ": BraiiiiiiinnnzzzZ...\033[0m" 
				<< std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
	std::cout << "\033[93;3m"
				<< "Named the Zombie "
				<< this->_name 
				<< "\033[0m" 
				<< std::endl;
}
