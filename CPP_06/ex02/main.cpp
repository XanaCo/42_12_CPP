/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/20 19:52:51 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"
#include <stdlib.h>
#include <iostream>
#include <ctime>

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base Obj0;
	Base *Obj1 = generate();
	Base *Obj2 = generate();
	Base *Obj3 = generate();
	Base *Obj4 = generate();
	Base *Obj5 = generate();

	std::cout << "-Idenfication PTR :-" << std::endl;

	std::cout << "Obj0 Type : ";
	identify(&Obj0);
	std::cout << "Obj1 Type : ";
	identify(Obj1);
	std::cout << "Obj2 Type : ";
	identify(Obj2);
	std::cout << "Obj3 Type : ";
	identify(Obj3);
	std::cout << "Obj4 Type : ";
	identify(Obj4);
	std::cout << "Obj5 Type : ";
	identify(Obj5);

	std::cout << "-Idenfication & :-" << std::endl;

	std::cout << "Obj0 Type : ";
	identify(Obj0);
	std::cout << "Obj1 Type : ";
	identify(*Obj1);
	std::cout << "Obj2 Type : ";
	identify(*Obj2);
	std::cout << "Obj3 Type : ";
	identify(*Obj3);
	std::cout << "Obj4 Type : ";
	identify(*Obj4);
	std::cout << "Obj5 Type : ";
	identify(*Obj5);

	delete Obj1;
	delete Obj2;
	delete Obj3;
	delete Obj4;
	delete Obj5;
	
	return (EXIT_SUCCESS);
}
