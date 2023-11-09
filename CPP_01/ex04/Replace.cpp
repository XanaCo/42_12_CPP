/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/08 15:00:40 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	copy_and_replace(std::string in, std::string out, std::string s1, std::string s2) {

	std::fstream ifs, ofs;
	std::stringstream file_buffer;
	std::string	one_line;
	std::size_t i = 0;

	ifs.open(in.c_str(), std::ios::in);
	if (!ifs)
	{
		std::cerr << "Error: Could not open " << in << std::endl;
		return (EXIT_FAILURE);
	}
	ofs.open(out.c_str(), std::ios::out);
	if (!ofs)
	{
		ifs.close();
		std::cerr << "Error: Could not open " << out << std::endl;
		return (EXIT_FAILURE);
	}

	file_buffer << ifs.rdbuf();
	one_line = file_buffer.str();
	while (one_line.size() > i)
	{
		if (one_line.substr(i, s1.size()) == s1)
		{
			ofs << s2;
			i += s1.size();
		}
		else
			ofs << one_line[i++];
	}
	ifs.close();
	ofs.close();

	return (EXIT_SUCCESS);
}
