/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/26 23:34:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*CONSTRUCTORS*/

Contact::Contact(void) {

	return ;
}

/*DESTRUCTORS*/

Contact::~Contact(void) {

	return ;
}

/*MEMBERS*/

void	Contact::set_contact(void) {

	this->_firstname.clear();
	this->_lastname.clear();
	this->_nickname.clear();
	this->_phonenumber.clear();
	this->_darksecret.clear();

	std::cout << std::endl;
	
	while (!this->_firstname.length() && !std::cin.eof())
	{
		std::cout << "	First name: ";
		getline(std::cin, this->_firstname);
	}
	while (!this->_lastname.length() && !std::cin.eof())
	{
		std::cout << "	Last name: ";
		getline(std::cin, this->_lastname);
	}
	while (!this->_nickname.length() && !std::cin.eof())
	{
		std::cout << "	Nickname: ";
		getline(std::cin, this->_nickname);
	}
	while (!this->_phonenumber.length() && !std::cin.eof())
	{
		std::cout << "	Phone Number: ";
		getline(std::cin, this->_phonenumber);
	}
	while (!this->_darksecret.length() && !std::cin.eof())
	{
		std::cout << "	Darkest Secret: ";
		getline(std::cin, this->_darksecret);
	}
	std::cout << std::endl;

	return ;
}

void	Contact::print_contact(void) const {

	std::cout << "\033[97;1m - - - - - - - - - - - - - - " << std::endl;
	std::cout << " First Name : " << this->_firstname << std::endl;
	std::cout << " Last Name : " << this->_lastname << std::endl;
	std::cout << " Nickname : " << this->_nickname << std::endl;
	std::cout << " Phone Number : " << this->_phonenumber << std::endl;
	std::cout << " Darkest Secret : " << this->_darksecret << std::endl;
	std::cout << " - - - - - - - - - - - - - - \033[0m" << std::endl;

	return ;
}

std::string Contact::trim_string(std::string str) const {

	std::string	res;
	int			len;
	int			spaces;

	for (int i = 0; str[i]; i++)
	{	
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 27 || str[i] == 127 || str[i] == 28)
			str[i] = 32;
	}
	len = str.length();
	spaces = 10 - len;

	if (len < 10)
	{
		res.append(spaces, ' ');
		res.insert(spaces, str);
	}
	else
	{
		res = str.substr(0, 9);
		res += ".";
	}
	
	return res;
}

void Contact::get_data(int index) const {

	std::cout << std::endl
				<< "\033[97;1m	|         "
				<< index
				<< "|"
				<< trim_string(this->_firstname)
				<< "|"
				<< trim_string(this->_lastname)
				<< "|"
				<< trim_string(this->_nickname)
				<< "|\033[0m"
				<< std::endl;
}
