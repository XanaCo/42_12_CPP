/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/26 23:20:22 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <istream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	line;

	std::cout << "Please enter ADD SEARCH or EXIT: ";
	while (getline(std::cin, line))
	{
		if (!line.compare("ADD"))
			book.add_contact();
		else if (!line.compare("SEARCH"))
			book.search_contact();
		else if (!line.compare("EXIT"))
			return 0;
		else
			std::cout << "Please enter ADD SEARCH or EXIT: ";
	}
	return 0;
	
}