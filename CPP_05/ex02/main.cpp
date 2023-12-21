/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 16:53:44 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat PepeNobody("Pepe", 101);
		Bureaucrat JoseBoss("Jose", 6);
	
		std::cout << PepeNobody << std::endl;
		std::cout << JoseBoss << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm zero ("Home");
		RobotomyRequestForm one ("Bender");
		PresidentialPardonForm two ("Marvin");

		std::cout << WHITE << "	Forms created :" << END_COLOR << std::endl;
		std::cout << zero << std::endl;
		std::cout << one << std::endl;
		std::cout << two << std::endl;

		std::cout << WHITE << "	Jose signs Forms zero and one :" << END_COLOR << std::endl;
		JoseBoss.signForm(zero);
		JoseBoss.signForm(one);
		//std::cout << WHITE << "	Pepe signs Form two :" << END_COLOR << std::endl;
		//PepeNobody.signForm(two);
		JoseBoss.signForm(two);

		std::cout << WHITE << "	Forms now :" << END_COLOR << std::endl;
		std::cout << zero << std::endl;
		std::cout << one << std::endl;
		std::cout << two << std::endl;

		std::cout << WHITE << "	Execution of Forms :" << END_COLOR << std::endl;
		PepeNobody.executeForm(zero);
		std::cout << std::endl;
		JoseBoss.executeForm(one);
		JoseBoss.executeForm(one);
		JoseBoss.executeForm(one);
		std::cout << std::endl;
		
		std::cout << WHITE << "	Promotion and execution :" << END_COLOR << std::endl;
		std::cout << JoseBoss << std::endl;
		JoseBoss.bureaucratPromotion();
		std::cout << JoseBoss << std::endl;
		JoseBoss.executeForm(two);
		std::cout << std::endl;

		//two.beSigned(PepeNobody);

	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	return 0;
}
