/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 14:11:33 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

	ClapTrap Def;
	ClapTrap Pepe("Pepito");
	
	Def = Pepe;
	
	Pepe.attack("Pedro");
	Pepe.takeDamage(1);
	Pepe.beRepaired(12);
	Pepe.takeDamage(9);
	Pepe.beRepaired(2);
	Pepe.attack("Juan");
	Pepe.takeDamage(5);
	Pepe.attack("Juan");
	Pepe.beRepaired(1);

	std::cout << " --- " << std::endl;
	
	Def.attack("Another Pedro");
	Def.takeDamage(1);
	Def.beRepaired(12);
	Def.takeDamage(9);
	Def.beRepaired(2);
	Def.attack("Another Juan");
	Def.takeDamage(5);
	Def.attack("Another Juan");
	Def.beRepaired(1);

}