/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/20 23:39:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

// TEST Exception tooLow
	try
	{
		std::cout << std::endl;

		Bureaucrat Pepe("Pepe", 25);
		Bureaucrat Jose("Jose", 6);

		//std::cout << Pepe << std::endl;
		std::cout << Jose << std::endl;

		std::cout << std::endl;
		
		ShrubberyCreationForm zero ("Home");
		RobotomyRequestForm one ("Bender");
		PresidentialPardonForm two ("Marvin");

		std::cout << zero << std::endl;
		std::cout << one << std::endl;
		std::cout << two << std::endl;

		std::cout << std::endl;

		Jose.signForm(zero);
		Jose.signForm(one);
		Pepe.signForm(two);

		std::cout << std::endl;
	
		std::cout << zero << std::endl;
		std::cout << one << std::endl;
		std::cout << two << std::endl;

		zero.execute(Pepe);
		std::cout << std::endl;
		one.execute(Jose);
		std::cout << std::endl;
		Jose.bureaucratPromotion();
		std::cout << Jose << std::endl;
		two.execute(Jose);
		std::cout << std::endl;
		//two.beSigned(Pepe);

	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	return 0;
}


// int	main(void)
// {
// 	try
// 	{
// 		std::cout << "	Let's create things" << std::endl;
// 		PresidentialPardonForm form1("Alfred Dreyfus");
// 		RobotomyRequestForm form2("Isaac Assimov");
// 		ShrubberyCreationForm form3("Garden");
// 		RobotomyRequestForm form4("Daneel Olivaw");
// 		Bureaucrat bur1("Maxence, practicly prime minister,", 4);
// 		Bureaucrat bur2("Vincent, member of the PM office,", 10);
// 		Bureaucrat bur3("Damien, a middle manager,", 30);
// 		Bureaucrat bur4("Thomas, a middle gouverment worker,", 50);
// 		Bureaucrat bur5("Jean, a low employee,", 80);
// 		Bureaucrat bur6("Alexandre, basicaly nobody in the administration,", 140);
// 		Bureaucrat bur7("Adrien, just better than an intern,", 147);
// 		std::cout << std::endl;

// 		std::cout << "	Let's have a look at my forms" << std::endl;
// 		std::cout << form1 << std::endl;
// 		std::cout << form2 << std::endl;
// 		std::cout << form3 << std::endl;
// 		std::cout << std::endl;

// 		std::cout << "	Let's test of the ShrubberyCreationForm" << std::endl;
// 		bur7.signForm(form3);
// 		std::cout << form3 << std::endl;
// 		bur6.executeForm(form3);
// 		bur6.signForm(form3);
// 		std::cout << form3 << std::endl;
// 		bur6.executeForm(form3);
// 		bur5.executeForm(form3);
// 		std::cout << std::endl;
		
// 		std::cout << "	Let's test of the RobotomyRequestForm" << std::endl;
// 		bur5.signForm(form2);
// 		std::cout << form2 << std::endl;
// 		bur4.executeForm(form2);
// 		bur4.signForm(form2);
// 		std::cout << form2 << std::endl;
// 		bur4.executeForm(form2);
// 		bur3.executeForm(form2);
// 		bur3.signForm(form4);
// 		std::cout << form4 << std::endl;
// 		bur3.executeForm(form4);
// 		bur3.executeForm(form4);
// 		bur3.executeForm(form4);
// 		std::cout << std::endl;

// 		std::cout << "	Test of the PresidentialPardonForm" << std::endl;
// 		bur3.signForm(form1);
// 		std::cout << form1 << std::endl;
// 		bur2.executeForm(form1);
// 		std::cout << form1 << std::endl;
// 		bur2.signForm(form1);
// 		bur2.executeForm(form1);
// 		bur1.executeForm(form1);
// 		std::cout << std::endl;

// 		std::cout << "	Let's destroy everything" << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
// 	}
// 	return (0);
// }