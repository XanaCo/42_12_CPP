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

PhoneBook::PhoneBook(void)
{
	//std::cout << "PhoneBook Constructor called" << std::endl;
	this->_index = 0;
	this->_ncontacts = 0;
	return ;
}

/*DESTRUCTORS*/

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook Destructor called" << std::endl;
	return ;
}

/*MEMBER FUNCTIONS*/

void	PhoneBook::search_contact(void) const
{
	std::string	input;
	int			i;
	
	for (i = 0; i < this->_ncontacts; i++)
		this->_tab[i].get_data(i);
	if (!this->_ncontacts)
		std::cout << "\033[31;1mYou should add some contacts!\033[0m" << std::endl;
	if (!input.length() && !std::cin.eof() && this->_ncontacts)
	{
		std::cout << std::endl << "	Enter contact index: ";
		getline(std::cin, input);
		if (input.length() == 1 && input.at(0) - '0' >= 0 && input.at(0) - '0' < this->_ncontacts)
			this->_tab[input.at(0) - '0'].print_contact();
		else
			std::cout << "\033[31;1mWrong index!\033[0m" << std::endl;
	}
	std::cout << "Please enter ADD SEARCH or EXIT: ";
	return ;
}

void	PhoneBook::add_contact(void)
{
	if (this->_ncontacts >= CONTACT_MAX)
		this->_ncontacts = CONTACT_MAX;
	if (this->_index == CONTACT_MAX)
		this->_index = 0;
	// std::cout << "n CONTACTS: " << this->_ncontacts << std::endl;
	// std::cout << "INDEX: " << this->_index << std::endl;
	this->_tab[this->_index].set_contact();
	this->_ncontacts++;
	this->_index++;
	return ;
}