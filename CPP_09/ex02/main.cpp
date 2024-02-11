/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/10 20:35:30 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) // secuence de chiffres!!
	{
		std::cerr << RED << "Error: Wrong number of arguments" << END_COLOR << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		// start here
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END_COLOR << '\n';
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}