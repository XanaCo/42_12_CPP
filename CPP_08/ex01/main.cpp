/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/31 18:34:33 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(20);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		Span copy(sp);
		
		std::set<int> spanito = sp.getSpan();
		std::set<int> spanitoCopy = copy.getSpan();

		for (std::set<int>::iterator it = spanito.begin(); it != spanito.end(); it++)
			std::cout << " " << *it << std::endl;

		std::cout << WHITE << "SHORTEST SPAN : " << sp.shortestSpan() << END_COLOR << std::endl;
		std::cout << WHITE << "LONGEST SPAN : " << sp.longestSpan() << std::endl;

		for (std::set<int>::iterator it = spanitoCopy.begin(); it != spanitoCopy.end(); it++)
			std::cout << " " << *it << std::endl;

		std::cout << YELLOW << "SHORTEST SPAN copy: " << copy.shortestSpan() << END_COLOR << std::endl;
		std::cout << YELLOW << "LONGEST SPAN copy: " << copy.longestSpan() << END_COLOR << std::endl;
		
		std::list<int> lst;
		for (int i = 0; i < 5; i++)
			lst.push_back(std::rand() % 100);
		sp.addRange(lst.begin(), lst.end());

		spanito = sp.getSpan();

		for (std::set<int>::iterator it = spanito.begin(); it != spanito.end(); it++)
			std::cout << " " << *it << std::endl;

		std::cout << WHITE << "SHORTEST SPAN : " << sp.shortestSpan() << END_COLOR << std::endl;
		std::cout << WHITE << "LONGEST SPAN : " << sp.longestSpan() << END_COLOR << std::endl;

		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(std::rand() % 1000);
		sp.addRange(vec.begin(), vec.end());

		spanito = sp.getSpan();

		for (std::set<int>::iterator it = spanito.begin(); it != spanito.end(); it++)
			std::cout << " " << *it << std::endl;

		std::cout << WHITE << "SHORTEST SPAN : " << sp.shortestSpan() << END_COLOR << std::endl;
		std::cout << WHITE << "LONGEST SPAN : " << sp.longestSpan() << END_COLOR << std::endl;

		// Span max = Span(10000);
	
		// std::vector<int> maxi;
		// for (int i = 0; i < 10000; i++)
		// 	maxi.push_back(std::rand() % 10000);
		// max.addRange(maxi.begin(), maxi.end());

		// std::set<int> spanitoM = max.getSpan();

		// for (std::set<int>::iterator it = spanitoM.begin(); it != spanitoM.end(); it++)
		// 	std::cout << " " << *it << std::endl;

		// std::cout << WHITE << "SHORTEST SPAN : " << max.shortestSpan() << END_COLOR << std::endl;
		// std::cout << WHITE << "LONGEST SPAN : " << max.longestSpan() << END_COLOR << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
	}

	return 0;
}