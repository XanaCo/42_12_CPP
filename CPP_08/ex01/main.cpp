/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/29 23:33:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(6);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(1);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::set<int> spanito = sp.getSpan();


	for (std::set<int>::iterator it = spanito.begin(); it != spanito.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "SHORTEST SPAN : " << sp.shortestSpan() << std::endl;
	std::cout << "LONGEST SPAN : " << sp.longestSpan() << std::endl;
	
	return 0;
}