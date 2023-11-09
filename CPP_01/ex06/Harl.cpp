/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 20:46:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*CONSTRUCTORS*/

Harl::Harl(void) {

	std::cout << WHITE_C << "Hello, I am Harl!" << END_COLOR << std::endl << std::endl;
	return ;
}

/*DESTRUCTORS*/

Harl::~Harl(void) {

	std::cout << WHITE_C << "Bye, see you soon" << END_COLOR << std::endl << std::endl;
	return ;
}

/*MEMBER Public FUNCTION*/

void	Harl::complain(std::string level) {

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}

	switch (i)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break ;
		default:
			std::cout << WHITE_C 
						<< "[Probably complaining about something in the background]"
						<< END_COLOR
						<< std::endl;
			break ;
	}
	return ;
}

/*MEMBER Private FUNCTIONS*/

void	Harl::_debug(void) {
	
	std::cout << GREEN 
				<< "[ DEBUG ]" 
				<< std::endl
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do !"
				<< std::endl
				<< std::endl;
	return ;
}

void	Harl::_info(void) {
	
	std::cout << BLUE
				<< "[ INFO ]" 
				<< std::endl
				<< "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger !\nIf you did, I wouldn’t be asking for more !"
				<< std::endl
				<< std::endl;
	return ;
}

void	Harl::_warning(void) {

	std::cout << YELLOW
				<< "[ WARNING ]" 
				<< std::endl
				<< "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
				<< std::endl
				<< std::endl;
	return ;
}

void	Harl::_error(void) {

	std::cout << RED
				<< "[ ERROR ]" 
				<< std::endl
				<< "This is unacceptable !\nI want to speak to the manager now."
				<< END_COLOR 
				<< std::endl
				<< std::endl;
	return ;
}