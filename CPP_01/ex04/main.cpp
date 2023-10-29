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

#include "Program.hpp"

int main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	
	if (argc != 4)
	{
		std::cout << "Usage: ./exec <filename> <string1> <string2>" << std::endl;
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	
	return (EXIT_SUCCESS);
}