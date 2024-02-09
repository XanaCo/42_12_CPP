/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:14:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

	ClapTrap Pepe("Pepito");
	std::cout << std::endl;
	ScavTrap Pedro("Pedro");
	std::cout << std::endl;
	FragTrap Pol("Pol");
	
	Pepe.attack("Juan");
	Pedro.attack("Juan");
	Pol.attack("Juan");

	Pepe.takeDamage(1);
	Pedro.takeDamage(1);
	Pol.takeDamage(1);
	
	Pepe.beRepaired(12);
	Pedro.beRepaired(12);
	Pol.beRepaired(12);

	Pepe.takeDamage(9);
	Pedro.takeDamage(9);
	Pol.takeDamage(9);

	Pepe.display_info();
	Pedro.display_info();
	Pol.display_info();
	
	Pedro.guardGate();
	Pol.highFivesGuys();

	Pepe.beRepaired(2);
	Pedro.beRepaired(2);
	Pol.beRepaired(2);

	Pepe.attack("Juan");
	Pedro.attack("Juan");
	Pol.attack("Juan");

	Pepe.takeDamage(5);
	Pedro.takeDamage(5);
	Pol.takeDamage(5);
	
	Pepe.attack("Juan");
	Pedro.attack("Juan");
	Pol.attack("Juan");
	
	Pepe.beRepaired(1);
	Pedro.beRepaired(1);
	Pol.beRepaired(1);

	Pepe.display_info();
	Pedro.display_info();
	Pol.display_info();

	return 0;

}