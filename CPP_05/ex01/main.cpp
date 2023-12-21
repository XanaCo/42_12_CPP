/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 17:35:03 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
// TEST Creation High/low
	try
	{
		//Bureaucrat Paco("", 130);
		Bureaucrat Paco("Paquito", -1);
		//Bureaucrat Paco("Paquito", 1);
		//Bureaucrat Paco("Paquito", 150);
		//Bureaucrat Paco("Paquito", -111111111111111111);
		//Bureaucrat Paco("Paquito", 190);
		//Bureaucrat Paco("Paquito", 151);
		//Bureaucrat unknown;
		//std::cout << unknown << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

// TEST Exception tooLow
	try
	{
		std::cout << std::endl;

		Bureaucrat Pepe("Pepe", 150);
		Bureaucrat Jose("Jose", 10);

		std::cout << Pepe << std::endl;
		std::cout << Jose << std::endl;

		std::cout << std::endl;
				
		Form zero;
		Form one("28C", 10, 15);
		Form two("89B", 42, 2);

		std::cout << zero << std::endl;
		std::cout << one << std::endl;
		std::cout << two << std::endl;

		std::cout << std::endl;

		Jose.signForm(one);
		std::cout << one << std::endl;

		std::cout << std::endl;

		Pepe.signForm(two); // TRY stops here, calls DESTRUCTORS and jumps to CATCH
		std::cout << two << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	return 0;
}


