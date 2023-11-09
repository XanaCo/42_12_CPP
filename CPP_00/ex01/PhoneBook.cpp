/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/26 23:35:14 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*CONSTRUCTORS*/

PhoneBook::PhoneBook(void) {

	this->_index = 0;
	this->_ncontacts = 0;
	return ;
}

/*DESTRUCTORS*/

PhoneBook::~PhoneBook(void) {

	return ;
}

/*MEMBERS*/

void	PhoneBook::search_contact(void) const {

	std::string	input;
	
	for (int i = 0; i < this->_ncontacts; i++)
		this->_tab[i].get_data(i);

	if (!this->_ncontacts)
		std::cout << "\033[31;1mYou should add some contacts!\033[0m" << std::endl;

	if (this->_ncontacts && !input.length() && !std::cin.eof())
	{
		std::cout << std::endl << "	Enter contact index: ";
		getline(std::cin, input);
		if (input.length() == 1 && input.at(0) - '0' >= 0 && input.at(0) - '0' < this->_ncontacts)
			this->_tab[input.at(0) - '0'].print_contact();
		else
			std::cout << "\033[31;1mWrong index!\033[0m" << std::endl;
	}

	return ;
}

void	PhoneBook::add_contact(void) {

	if (this->_ncontacts >= CONTACT_MAX)
		this->_ncontacts = CONTACT_MAX;

	if (this->_index == CONTACT_MAX)
		this->_index = 0;

	this->_tab[this->_index].set_contact();

	if (this->_ncontacts < CONTACT_MAX)
		this->_ncontacts++;
	this->_index++;

	return ;
}