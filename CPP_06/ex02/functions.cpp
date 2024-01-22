/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/22 15:51:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "ABC.hpp"

Base *generate(void) {

	Base	*res;
	int		num;
	
	num = rand() % 3;
	//std::cout << "Type generation number : " << num << std::endl;
	
	if (num == 0)
		res = new A;
	else if (num == 1)
		res = new B;
	else
		res = new C;
	
	return res;
}

void identify(Base* p) {
	
	if (dynamic_cast<A*>(p))
		std::cout << "'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "'C'" << std::endl;
	else if (dynamic_cast<A*>(p) == NULL || dynamic_cast<B*>(p) == NULL || dynamic_cast<C*>(p) == NULL)
		std::cout << "The object is not from A, B or C class. (*)" << std::endl;

}

void identify(Base& p) {
	
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "'A'" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "'B'" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "'C'" << std::endl;
		else
			throw 404;
	}
	catch (int error)
	{
		std::cerr << "The object is not from A, B or C class. (&)" << std::endl;
	}
}