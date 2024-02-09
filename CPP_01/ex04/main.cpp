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

#include "Replace.hpp"

int main(int argc, char **argv)
{
	std::string filename_in, filename_out, s1, s2;

	if (argc != 4)
	{
		std::cerr << "Error: Use: ./executable <filename> <string1> <string2>" << std::endl;
		return (EXIT_FAILURE);
	}
	filename_in = argv[1];
	filename_out = filename_in + ".replace";
	s1 = argv[2];
	s2 = argv[3];
	if (filename_in.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: <filename> or <string> not found" << std::endl;
		return (EXIT_FAILURE);
	}
	if (copy_and_replace(filename_in, filename_out, s1, s2))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
