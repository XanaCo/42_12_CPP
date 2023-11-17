/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/17 22:45:53 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
// TEST Creation High/low
	try
	{
		Bureaucrat Paco("", 151);
		//Bureaucrat Paco("Paquito", -1);
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
		Bureaucrat Jose("Jose", 12);
		Bureaucrat unknown;

		std::cout << std::endl;

		std::cout << Pepe << std::endl;
		std::cout << Jose << std::endl;
		std::cout << unknown << std::endl;

		unknown = Jose;
		std::cout << unknown << std::endl;

		std::cout << Jose << std::endl;
		Jose.bureaucratPromotion();
		std::cout << Jose << std::endl << std::endl;
		
		Pepe.bureaucratDemotion(); // TRY stops here, calls DESTRUCTORS and jumps to CATCH

		std::cout << "This line is here for nothing!" << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

// TEST Exception tooHigh
	try
	{
		std::cout << std::endl;
		
		Bureaucrat Pepe("Pepe", 38);
		Bureaucrat Jose("Jose", 2);

		std::cout << std::endl;

		std::cout << Jose << std::endl;
		Jose.bureaucratPromotion();
		std::cout << Jose << std::endl << std::endl;
		
		Jose.bureaucratPromotion(); // TRY stops here calls DESTRUCTORS and jumps to CATCH

		std::cout << "This line is here for nothing!" << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}
	
	return 0;
}


