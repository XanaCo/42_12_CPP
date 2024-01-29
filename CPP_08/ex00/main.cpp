/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/29 23:40:48 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <vector>
#include <list>
#include <map>
#include "easyfind.hpp"

#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define YELLOW "\033[33;1m"
#define WHITE "\033[37;1m"
#define END_COLOR "\033[0m"

int main()
{

//CHECK with <vector> container
	std::vector<int> aVector;
	std::vector<int>::iterator itV;
	int resV = 0;

	aVector.push_back(1);
	aVector.push_back(2);
	aVector.push_back(7);
	aVector.push_back(4);
	aVector.push_back(5);

	std::cout << YELLOW << "	----------" << END_COLOR << std::endl;
	std::cout << YELLOW << "Check the content of my <vector> :" << END_COLOR << std::endl;
	for (itV = aVector.begin(); itV != aVector.end(); itV++)
		std::cout  << WHITE << " " << *itV << END_COLOR << std::endl;
	std::cout << YELLOW << "	----------" << END_COLOR << std::endl;

	try
	{
		std::cout << GREEN << "Is there a 2 in my <vector> :" << END_COLOR << std::endl;
		resV = *easyfind< std::vector<int> >(aVector, 2);
		std::cout << resV << std::endl;

		std::cout << GREEN << "Is there a 7 in my <vector> :" << END_COLOR << std::endl;
		resV = *easyfind< std::vector<int> >(aVector, 7);
		std::cout << resV << std::endl;

		std::cout << GREEN << "Is there a 42 in my <vector> :" << END_COLOR << std::endl;
		resV = *easyfind< std::vector<int> >(aVector, 42);
		std::cout << resV << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
	}
	
//CHECK with <list> container
	std::list<int> aList;
	std::list<int>::iterator itL;
	int resL = 0;

	aList.push_back(39);
	aList.push_back(40);
	aList.push_back(41);
	aList.push_back(42);

	std::cout << YELLOW << "	----------" << END_COLOR << std::endl;
	std::cout << YELLOW << "Check the content of my <list> :" << END_COLOR << std::endl;
	for (itL = aList.begin(); itL != aList.end(); itL++)
		std::cout << WHITE << " " << *itL << END_COLOR << std::endl;
	std::cout << YELLOW << "	----------" << END_COLOR << std::endl;

	try
	{
		std::cout << GREEN << "Is there a 42 in my <list> :" << END_COLOR << std::endl;
		resL = *easyfind< std::list<int> >(aList, 42);
		std::cout << resL << std::endl;

		std::cout << GREEN << "Is there a 39 in my <list> :" << END_COLOR << std::endl;
		resL = *easyfind< std::list<int> >(aList, 39);
		std::cout << resL << std::endl;

		std::cout << GREEN << "Is there a -42 in my <list> :" << END_COLOR << std::endl;
		resL = *easyfind< std::list<int> >(aList, -42);
		std::cout << resL << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
	}

	return 0;
}
