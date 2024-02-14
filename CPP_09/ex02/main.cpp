/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/14 17:42:26 by ancolmen         ###   ########.fr       */
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
		PmergeMe data(argc, argv);

		std::cout << YELLOW << "Before :  " << END_COLOR;
		printContainer(data.getArray());
	
		double vectorTime = data.sort(data.getArray());
		double listTime = data.sort(data.getList());

		std::cout << GREEN << "After  :  " << END_COLOR;
		printContainer(data.getArray());

		std::cout << WHITE << "Time to process a range of " << data.getSize() << " elements with " << VECTOR << " : " << vectorTime << " us" << END_COLOR << std::endl;
		std::cout << WHITE << "Time to process a range of " << data.getSize() << " elements with " << LIST << " : " << listTime << " us" << END_COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}