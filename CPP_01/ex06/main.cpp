/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 21:56:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./executable <level>" << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::string	level = argv[1];
	if (level.empty())
	{
		std::cerr << "Error: <level> not found" << std::endl;
		return (EXIT_FAILURE);
	}

	Harl		Harlito;
	Harlito.complain(level);

	return (EXIT_SUCCESS);
}