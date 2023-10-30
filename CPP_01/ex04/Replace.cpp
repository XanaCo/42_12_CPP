/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 20:46:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	copy_and_replace(std::string in, std::string out, std::string s1, std::string s2) {

	std::fstream ifs, ofs;
	std::string	line;
	std::size_t	found;

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
	std::getline(ifs, line);
	while (!ifs.eof() && !line.empty())
	{
		found = line.find(s1);
		if (found != std::string::npos)
		{
			ofs << line.substr(0, found);
			ofs << s2;
			ofs << line.substr(found + s1.size(), line.size() - found - s1.size());
			ofs << std::endl;
		}
		else
			ofs << line << std::endl;
		std::getline(ifs, line);
	}
	ifs.close();
	ofs.close();
	return (EXIT_SUCCESS);
}
