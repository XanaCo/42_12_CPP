/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 19:20:24 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: Wrong number of arguments" << END_COLOR << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		PmergeMe sortNum(argc, argv);

		std::cout << "Before :  ";
		printContainer(sortNum.getArray());
	
		sortNum.sort(sortNum.getArray());
		sortNum.sort(sortNum.getList());

		std::cout << "After :  ";
		printContainer(sortNum.getList());

		sortNum.time(sortNum.getArray());
		sortNum.time(sortNum.getList());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}