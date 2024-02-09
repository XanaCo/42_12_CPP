/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/01 18:06:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> mlist;
	std::vector<int> mvec;

	if (mstack.empty())
		std::cout << RED << "My Mutant Stack is empty for now! : " << mstack.size() << END_COLOR << std::endl << std::endl;
	if (mlist.empty())
		std::cout << RED << "My List is empty for now! : " << mstack.size() << END_COLOR << std::endl << std::endl;
	if (mvec.empty())
		std::cout << RED << "My Vector is empty for now! : " << mstack.size() << END_COLOR << std::endl << std::endl;

	mstack.push(5);
	mstack.push(17);
	mstack.push(42);

	mlist.push_back(5);
	mlist.push_back(17);
	mlist.push_back(42);

	mvec.push_back(5);
	mvec.push_back(17);
	mvec.push_back(42);

	std::cout << BLUE << "Size of my stack is : " << mstack.size() << END_COLOR << std::endl;
	std::cout << BLUE << "First element of my stack is : " << mstack.top() << END_COLOR << std::endl;

	std::cout << YELLOW << "Size of my list is : " << mlist.size() << END_COLOR << std::endl;
	std::cout << YELLOW << "First element of my list is : " << mlist.back() << END_COLOR << std::endl;

	std::cout << MAGENTA << "Size of my vector is : " << mvec.size() << END_COLOR << std::endl;
	std::cout << MAGENTA << "First element of my vector is : " << mvec.back() << END_COLOR << std::endl;

	mstack.pop();
	mlist.pop_back();
	mvec.pop_back();
	
	std::cout << BLUE << "Size of my stack is now : " << mstack.size() << END_COLOR << std::endl;
	std::cout << BLUE << "First element of my stack is : " << mstack.top() << END_COLOR << std::endl;

	std::cout << YELLOW << "Size of my list is now : " << mlist.size() << END_COLOR << std::endl;
	std::cout << YELLOW << "First element of my list is : " << mlist.back() << END_COLOR << std::endl;

	std::cout << MAGENTA << "Size of my vector is : " << mvec.size() << END_COLOR << std::endl;
	std::cout << MAGENTA << "First element of my vector is : " << mvec.back() << END_COLOR << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	mvec.push_back(3);
	mvec.push_back(5);
	mvec.push_back(737);
	mvec.push_back(0);

	std::cout << BLUE << "Size of my stack is now : " << mstack.size() << END_COLOR << std::endl;
	std::cout << BLUE << "First element of my stack is : " << mstack.top() << END_COLOR << std::endl;

	std::cout << YELLOW << "Size of my list is now : " << mlist.size() << END_COLOR << std::endl;
	std::cout << YELLOW << "First element of my list is : " << mlist.back() << END_COLOR << std::endl;

	std::cout << MAGENTA << "Size of my vector is : " << mvec.size() << END_COLOR << std::endl;
	std::cout << MAGENTA << "First element of my vector is : " << mvec.back() << END_COLOR << std::endl;

//CHECK mutant stack contents
	std::cout << BLUE << "MY STACK : " << END_COLOR << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

//CHECK list contents
	std::cout << YELLOW << "MY LIST : " << END_COLOR << std::endl;

	std::list<int>::iterator itL = mlist.begin();
	std::list<int>::iterator iteL = mlist.end();
	++itL;
	--itL;

	while (itL != iteL)
	{
		std::cout << *itL << std::endl;
		++itL;
	}

//CHECK vector contents
	std::cout << MAGENTA << "MY VECTOR : " << END_COLOR << std::endl;

	std::vector<int>::iterator itV = mvec.begin();
	std::vector<int>::iterator iteV = mvec.end();
	++itV;
	--itV;

	while (itV != iteV)
	{
		std::cout << *itV << std::endl;
		++itV;
	}
	
//CHECK if construction by copy works with my stack
	std::stack<int> s(mstack);

//CHECK if emplace+swap functions are also inherited (not c++98)
	// s.emplace(42);
	// mstack.swap(s);

	// //CHECK mutant stack contents
	// std::cout << CYAN << "MY STACK copy : " << END_COLOR << std::endl;

	// MutantStack<int>::iterator itC = mstack.begin();
	// MutantStack<int>::iterator iteC = mstack.end();
	// ++itC;
	// --itC;

	// while (itC != iteC)
	// {
	// 	std::cout << *itC << std::endl;
	// 	++itC;
	// }

	return 0;

}