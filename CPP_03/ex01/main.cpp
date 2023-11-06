/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:14:58 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	ClapTrap Pepe("Pepito");
	ScavTrap Pedro("Pedro");
	
	Pepe.attack("Juan");
	Pedro.attack("Juan");

	Pepe.takeDamage(1);
	Pedro.takeDamage(1);
	
	Pepe.beRepaired(12);
	Pedro.beRepaired(12);

	Pepe.takeDamage(9);
	Pedro.takeDamage(9);

	Pepe.display_info();
	Pedro.display_info();
	
	Pedro.guardGate();

	Pepe.beRepaired(2);
	Pedro.beRepaired(2);

	Pepe.attack("Juan");
	Pedro.attack("Juan");

	Pepe.takeDamage(5);
	Pedro.takeDamage(5);
	
	Pepe.attack("Juan");
	Pedro.attack("Juan");
	
	Pepe.beRepaired(1);
	Pedro.beRepaired(1);

	Pepe.display_info();
	Pedro.display_info();

	return 0;

}