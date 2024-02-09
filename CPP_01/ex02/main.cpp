/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 18:13:19 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "\033[93;3m" << "STR Address: " << &str << "\033[0m" << std::endl;
	std::cout << "\033[94;3m" << "PTR Stocked Address: " << stringPTR << "\033[0m" << std::endl;
	std::cout << "\033[95;3m" << "REF Stocked Address: " << &stringREF << "\033[0m" << std::endl;

	std::cout << std::endl;

	std::cout << "\033[93;3m" << "STR Content: " << str << "\033[0m" << std::endl;
	std::cout << "\033[94;3m" << "PTR Pointed Value: " << *stringPTR << "\033[0m" << std::endl;
	std::cout << "\033[95;3m" << "REF Pointed Value: " << stringREF << "\033[0m" << std::endl;

	return 0;
}