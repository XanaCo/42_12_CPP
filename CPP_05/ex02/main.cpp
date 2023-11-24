/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/24 18:02:25 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

// TEST Exception tooLow
	try
	{
		std::cout << std::endl;

		Bureaucrat Pepe("Pepe", 150);
		Bureaucrat Jose("Jose", 10);

		std::cout << Pepe << std::endl;
		std::cout << Jose << std::endl;

		std::cout << std::endl;
				
		ShrubberyCreationForm one;
		ShrubberyCreationForm two;

		std::cout << one << std::endl;
		std::cout << two << std::endl;

		std::cout << std::endl;

		Jose.signForm(one);
		std::cout << one << std::endl;

		std::cout << std::endl;

		Pepe.signForm(two); // TRY stops here, calls DESTRUCTORS and jumps to CATCH
		std::cout << two << std::endl;

		std::cout << "This line is here for nothing!" << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cerr << std::endl << YELLOW << "WARNING : " << e.what() << END_COLOR << std::endl;
	}

	return 0;
}


