/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/08 15:54:25 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static std::string ScreamIt(std::string str)
{
	std::string res;

	for(size_t i = 0; i < str.size(); ++i)
		res += toupper(str[i]);
	return res;
}

int	main(int argc, char **argv)
{
	int i;

	

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (i = 1; i < argc; i++) {
			std::string str = argv[i];
			std::cout << ScreamIt(str);
		}
		std::cout << std::endl;
	}
	return 0;
}