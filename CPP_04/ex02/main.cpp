/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 21:58:34 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

// int main(void)
// {
// 	AAnimal *error;
// 	error = new AAnimal();
	
// 	return 0;
// }


int main(void)
{
//Poly_01 TESTS

	std::cout << std::endl << " A Dog is born :" << std::endl;
	const AAnimal* a = new Dog();
	std::cout << std::endl << " A Cat is born :" << std::endl;
	const AAnimal* b = new Cat();
	std::cout << std::endl;
	
	std::cout << "Dog Type : " << a->getType() << std::endl;
	a->makeSound();
	std::cout << "Cat Type : " <<  b->getType() << std::endl;
	b->makeSound();
	
	std::cout << std::endl;
	delete a;
	delete b;
	std::cout << std::endl;
	
//Poly_02 TESTS

	AAnimal *AnimalTab[8];
	std::string dogIdeas[5] = {"I will cuddle all humans", "Ball, oh, ball!", "I was waiting for you", "I love this shoe", "That smells delicious"};
	std::string catIdeas[5] = {"I will slave all humans", "Where's my food", "I really don't like you", "I am bored", "I will break this glass"};
	
//Create 1/2 Dogs in tab, sets and shows ideas

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl << " Create Dog [" << i << "]" << std::endl;
		AnimalTab[i] = new Dog();
		for (int j = 0; j < IDEAS; j++)
		{
			((Dog *)AnimalTab[i])->setIdea(dogIdeas[rand() % 5], j);
			std::cout << "Dog number [" << i << "] thinks : ";
			Brain *D = ((Dog *)AnimalTab[i])->getDogBrain();
			std::cout << D->getIdea(j) << std::endl;
		}
	}
	
//Create 1/2 Cats in tab, sets and shows ideas

	for (int i = 4; i < 8; i++)
	{
		std::cout << std::endl << " Create Cat [" << i << "]" << std::endl;
		AnimalTab[i] = new Cat();
		for (int j = 0; j < IDEAS; j++)
		{
			std::cout << "Cat number [" << i << "] thinks : ";
			((Cat *)AnimalTab[i])->setIdea(catIdeas[rand() % 5], j);
			Brain *C = ((Cat *)AnimalTab[i])->getCatBrain();
			std::cout << C->getIdea(j) << std::endl;
		}
	}

	std::cout << std::endl << " --- " << std::endl << std::endl;

//Copy and test if its a true copy

	std::cout << " Create Fluffy " << std::endl;
	Dog Fluffy;
	
	for (int k = 0; k < IDEAS; k++)
		std::cout << "Fluffy initial idea " << k << ": " << Fluffy.getDogBrain()->getIdea(k) << std::endl;
	
	Fluffy = *((Dog *)AnimalTab[3]);
	for (int k = 0; k < IDEAS; k++)
		std::cout << "Fluffy new idea " << k << ": " << Fluffy.getDogBrain()->getIdea(k) << std::endl;

//Delete and free allocated memory
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::endl << " Delete Animal [" << i << "]" << std::endl;
		delete AnimalTab[i];
	}

	std::cout << std::endl << " Delete Fluffy " << std::endl;
	
	return 0;
}