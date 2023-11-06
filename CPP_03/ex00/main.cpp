/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 19:40:26 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

	ClapTrap Pepe("Pepito");
	
	Pepe.attack("Pedro");
	Pepe.takeDamage(1);
	Pepe.beRepaired(12);
	Pepe.takeDamage(9);
	Pepe.beRepaired(2);
	Pepe.attack("Juan");
	Pepe.takeDamage(5);
	Pepe.attack("Juan");
	Pepe.beRepaired(1);

}