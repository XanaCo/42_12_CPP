/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/15 15:53:29 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
// TESTS Creation / Destruction AMateria

	std::cout << std::endl << " Amateria Ice : " << std::endl;
	AMateria* ice = new Ice();
	std::cout << std::endl << " Amateria Cure : " << std::endl;
	AMateria* cure = new Cure();
	std::cout << std::endl << " Amateria Ice Copy : " << std::endl;
	AMateria* ice_clone = ice->clone();
	std::cout << std::endl << " Amateria Cure Copy : " << std::endl;
	AMateria* cure_clone = cure->clone();
	std::cout << std::endl << " Amateria Assignation : " << std::endl;
	AMateria* ice_assign = ice;
	std::cout << "No constructor called, assignation in place " << std::endl;
	std::cout << std::endl << " IMateriaSource :" << std::endl;
	IMateriaSource *matS = new MateriaSource();
	
	std::cout << std::endl;
	
	std::cout << "	AMateria " << ice->getType() << " stocked in address " << ice << std::endl;
	std::cout << "	AMateria " << cure->getType() << " stocked in address " << cure << std::endl;
	std::cout << "	AMateria Clone " << ice_clone->getType() << " stocked in address " << ice_clone << std::endl;
	std::cout << "	AMateria Clone " << cure_clone->getType() << " stocked in address " << cure_clone << std::endl;
	std::cout << "	AMateria Assign " << ice_assign->getType() << " stocked in address " << ice_assign << std::endl;
	std::cout << "	ImateriaSource stocked in address " << matS << std::endl;
	
	std::cout << std::endl;

	matS->learnMateria(ice); // ice inventory to matS
	matS->learnMateria(cure); // cure inventory to matS

	AMateria *ice_new = matS->createMateria("ice");
	AMateria *cure_new = matS->createMateria("cure");
	AMateria *unknown = matS->createMateria("unknown");

	std::cout << std::endl;

	std::cout << "	AMateria " << ice_new->getType() << " stocked in address " << ice_new << std::endl;
	std::cout << "	AMateria " << cure_new->getType() << " stocked in address " << cure_new << std::endl;
	std::cout << "	AMateria unknown stocked in address " << unknown << std::endl; // empty inventory and no type
	
	std::cout << std::endl;

// TESTS Characters

	std::cout << " Player 1 : " << std::endl;
	Character P1("Player_1");
	std::cout << " Player 2 : " << std::endl;
	Character P2("Player_2");
	std::cout << " Player 3 : " << std::endl;
	Character P3;

	P1.equip(unknown); // tries to equip unknown, sends an error
	
	P1.equip(ice_new); // equipes ice_new to the inventory
	P1.equip(cure_new); // equips cure_new to the inventory

	P2.equip(cure_clone); // equipes ice_new to the inventory
	P2.equip(ice_clone); // equips cure_new to the inventory

	std::cout << std::endl;

	P1.use (0, P2);
	P1.use (1, P2);
	P1.use (5, P2);

	std::cout << std::endl;

	P3 = P1;

	std::cout << std::endl;
	
	P3.use(0, P2);
	P3.use(-1, P2);
	P3.use(2, P2);
	P3.use(3, P2);
	P3.use(1, P2);

	std::cout << std::endl;

	AMateria *unequiped;
	unequiped = P3.getMat(1);
	if (unequiped)
		P3.unequip(1); // P3 unequips cure_new
	P2.equip(unequiped); // P2 equips cure_new

	std::cout << "P2 picked the unequiped up and " << std::endl;	
	P2.use(0, P3);
	P2.use(1, P3);
	P2.use(2, P3);
	P2.use(4, P3);
	P2.use(3, P3);

	std::cout << std::endl;
	
	// delete ice;
	// delete cure;
	// delete ice_clone; // deleted by Character P2 destructor
	// delete cure_clone; // deleted by Character P2 destructor
	// delete ice_new; // deleted by Character P1 destructor
	// delete cure_new; // deleted by Character P1 destructor
	delete matS; // deletes ice and cure inventories at the same time

	std::cout << std::endl;
	
	return 0;
}

// // SUBJECT MAIN

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }

