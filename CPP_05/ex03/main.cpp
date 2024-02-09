/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 17:45:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	Bureaucrat TheBoss("MrPresident", 1);
	Bureaucrat MrNobody("NoOne", 149);

	Intern oneIntern;
	Intern copyIntern(oneIntern);
	Intern anotherIntern;

	AForm	*zero;
	AForm	*one;
	AForm	*two;
	AForm	*three;

	try 
	{
	//TEST Shrubbery
		std::cout << "	Shrubbery Test:" << std::endl;
		std::cout << WHITE << "Intern should create a Shrubbery Form" << END_COLOR << std::endl;
		one = oneIntern.makeForm("Shrubbery", "Beautiful");
		if (one)
		{
			std::cout << one << " : " << *one << std::endl;
			std::cout << WHITE << "TheBoss signs the Shrubbery" << END_COLOR << std::endl;
			TheBoss.signForm(*one);
			std::cout << one << " : " << *one << std::endl;
			std::cout << WHITE << "TheBoss executes the Shrubbery" << END_COLOR << std::endl;
			TheBoss.executeForm(*one);
			std::cout << WHITE << "MrNobody tries to execute the form" << END_COLOR << std::endl;
			one->execute(MrNobody);
		}
		else
			std::cout << WHITE << "Nothing was created!" << END_COLOR << std::endl;

		delete one;
	}
	catch(const std::exception& e)
	{
		delete one;
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}
	
	try
	{
	//TEST Robotomy
		std::cout << "	Robotomy Test:" << std::endl;
		std::cout << WHITE << "Intern should create a Robotomy Form" << END_COLOR << std::endl;
		two = anotherIntern.makeForm("Robotomy", "Bender");
		if (two)
		{
			std::cout << two << " : " << *two << std::endl;
			std::cout << WHITE << "TheBoss signs the Robotomy" << END_COLOR << std::endl;
			two->beSigned(TheBoss);
			std::cout << two << " : " << *two << std::endl;
			std::cout << WHITE << "TheBoss executes the Robotomy" << END_COLOR << std::endl;
			two->execute(TheBoss);
			std::cout << WHITE << "TheBoss re-executes the Robotomy" << END_COLOR << std::endl;
			two->execute(TheBoss);
		}
		else
			std::cout << WHITE << "Nothing was created!" << END_COLOR << std::endl;

		delete two;
	}
	catch(const std::exception& e)
	{
		delete two;
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}
	
	try
	{
	//TEST Presidential Pardon
		std::cout << "	Presidential Pardon Test:" << std::endl;
		std::cout << WHITE << "Intern should create a Presidential Pardon Form" << END_COLOR << std::endl;
		three = copyIntern.makeForm("PresidentialPardon", "Marvin");
		if (three)
		{
			std::cout << three << " : " << *three << std::endl;
			std::cout << WHITE << "TheBoss signs the PresidentialPardon" << END_COLOR << std::endl;
			three->beSigned(TheBoss);
			std::cout << three << " : " << *three << std::endl;
			std::cout << WHITE << "TheBoss executes the PresidentialPardon" << END_COLOR << std::endl;
			three->execute(TheBoss);
		}
		else
			std::cout << WHITE << "Nothing was created!" << END_COLOR << std::endl;

		delete three;
	}
	catch(const std::exception& e)
	{
		delete three;
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	try
	{
	//TEST Something Else
		std::cout << "	Something Else Test:" << std::endl;
		std::cout << WHITE << "Intern tries to create something on his own" << END_COLOR << std::endl;
		zero = oneIntern.makeForm("MarvelousCreation", "SomethingWeird");
		if (zero)
		{
			std::cout << zero << " : " << *zero << std::endl;
			std::cout << WHITE << "TheBoss signs the MarvelousCreation" << END_COLOR << std::endl;
			zero->beSigned(TheBoss);
			std::cout << zero << " : " << *zero << std::endl;
			std::cout << WHITE << "TheBoss executes the MarvelousCreation" << END_COLOR << std::endl;
			zero->execute(TheBoss);
		}
		else
			std::cout << WHITE << "Nothing was created!" << END_COLOR << std::endl;
		
		delete zero;
	}
	catch(const std::exception& e)
	{
		delete zero;
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	return 0;
}
