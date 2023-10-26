/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/26 21:55:00 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {

public:
	Contact(void);
	~Contact(void);

	void set_contact(void);
	void print_contact(void) const;
	void get_data(int index) const;
	std::string trim_string(std::string str) const;
	
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darksecret;

};

#endif

