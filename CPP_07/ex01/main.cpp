/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/23 19:04:30 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "iter.hpp"

int main()
{
	double dTab[7] = {3.5, 1.2, 4.8, 8, 0, 9, 0.002};
	int inTab[3] = {1, 2, 3};
	std::string strTab[5] = {"Cacahuetes", "fritos", "en", "vinagre", "!"};

	std::cout << "	My doubleTab : " << std::endl;
	iter(dTab, 7, &printBlock);
	std::cout << "	My IntTab : " << std::endl;
	iter(inTab, 3, &printBlock);
	std::cout << "	My strTab : " << std::endl;
	iter(strTab, 5, &printBlock);
	std::cout << "	My strTab with an unsigned : " << std::endl;
	iter(strTab, -42, &printBlock);

	return (EXIT_SUCCESS);
}
