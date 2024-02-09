/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 15:24:39 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl << " An Animal is born :" << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl << " A Dog is born :" << std::endl;
	const Animal* a = new Dog();
	std::cout << std::endl << " A Cat is born :" << std::endl;
	const Animal* b = new Cat();
	std::cout << std::endl << " A WrongAnimal is born :" << std::endl;
	const WrongAnimal* c = new WrongAnimal();
	std::cout << std::endl << " A WrongCat is born :" << std::endl;
	const WrongAnimal* d = new WrongCat();
	std::cout << std::endl << " A WrongCat is born :" << std::endl;
	const WrongCat* e = new WrongCat();
	
	std::cout << std::endl << " --- " << std::endl << std::endl;

	std::cout << "Animal Type : " << meta->getType() << std::endl;
	std::cout << "Dog Type : " << a->getType() << std::endl;
	std::cout << "Cat Type : " <<  b->getType() << std::endl;
	std::cout << "WrongAnimal Type : " <<  c->getType() << std::endl;
	std::cout << "WrongCat Type : " <<  d->getType() << std::endl;
	std::cout << "WrongCat Type : " <<  e->getType() << std::endl;

	std::cout << std::endl << " --- " << std::endl << std::endl;

	std::cout << " Animal goes : " << std::endl;
	meta->makeSound(); //will output the Animal sound!
	std::cout << " Dog goes : " << std::endl;
	a->makeSound(); //will output the dog sound!
	std::cout << " Cat goes : " << std::endl;
	b->makeSound(); //will output the cat sound!
	std::cout << " WrongAnimal goes : " << std::endl;
	c->makeSound(); //will output the wronganimal sound!
	std::cout << " WrongCat goes : " << std::endl;
	d->makeSound(); //will output the wronganimal sound!
	std::cout << " WrongCat goes : " << std::endl;
	e->makeSound(); //will output the wrongcat sound!

	std::cout << std::endl << " --- " << std::endl;

	std::cout << std::endl << " Delete Meta :" << std::endl;
	delete meta;
	std::cout << std::endl << " Delete Dog :" << std::endl;
	delete a;
	std::cout << std::endl << " Delete Cat :" << std::endl;
	delete b;
	std::cout << std::endl << " Delete WrongAnimal :" << std::endl;
	delete c;
	std::cout << std::endl << " Delete WrongCat :" << std::endl;
	delete d;
	std::cout << std::endl << " Delete WrongCat :" << std::endl;
	delete e;

	return 0;
}