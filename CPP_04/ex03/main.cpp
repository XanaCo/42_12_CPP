/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:13:28 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


// int main(void)
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp = NULL;
	
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
// 	delete tmp;

// 	return 0;
// }

int main(void)
{
//Creation / Destruction AMateria

	std::cout << std::endl << " Ice :" << std::endl;
	AMateria* a = new Ice();
	std::cout << std::endl << " Cure :" << std::endl;
	AMateria* b = new Cure();
	std::cout << std::endl << " Generic :" << std::endl;
	AMateria *gen = NULL;
	std::cout << std::endl << " IMateriaSource :" << std::endl;
	IMateriaSource *src = NULL;
	std::cout << std::endl;
	
	
	std::cout << "Ice Type : " << a->getType() << std::endl;
	gen = src->createMateria("ice"); // invalid read 
	std::cout << "Cure Type : " <<  b->getType() << std::endl;
	gen = src->createMateria("cure"); // invalid read
	
	std::cout << std::endl;
	delete a;
	delete b;
	std::cout << std::endl;
	return 0;
}
