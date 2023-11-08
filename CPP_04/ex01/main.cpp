/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/08 19:28:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{

	Animal *AnimalTab[16];
	

	for (int i = 0; i <= 8; i++)
	{
		std::cout << std::endl << " Create Dog [" << i << "]" << std::endl;
		AnimalTab[i] = new Dog();
	}
		
	for (int i = 8; i <= 16; i++)
	{
		std::cout << std::endl << " Create Cat [" << i << "]" << std::endl;
		AnimalTab[i] = new Cat();
	}

	std::cout << std::endl << "-------" << std::endl << std::endl;

	
	// copie de dog ou cat c est une copie profonde
	// delete le tableau


	for (int i = 0; i <= 16; i++)
	{
		std::cout << std::endl << " Delete Animal [" << i << "]" << std::endl;
		delete AnimalTab[i];
	}

	return 0;
}