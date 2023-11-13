/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 14:43:48 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	std::cout << "Peter is born" << std::endl;
	DiamondTrap Peter("Peter");
	std::cout << std::endl << "Piotr is born" << std::endl;
	DiamondTrap Piotr("Piotr");
	std::cout << std::endl << "Generic is born" << std::endl;
	DiamondTrap Def;
	
	std::cout << " --- " << std::endl;
	
	Peter.whoAmI();
	Peter.display_info();
	Piotr.whoAmI();
	Piotr.display_info();
	
	Peter.attack("Piotr");
	Piotr.takeDamage(30);
	Piotr.whoAmI();
	Piotr.display_info();

	Peter.highFivesGuys();

	Piotr.guardGate();

	Def = Peter;
	Def.whoAmI();
	Def.display_info();
	Def = Piotr;
	Def.whoAmI();
	Def.display_info();

	std::cout << " --- " << std::endl;

	return 0;

}