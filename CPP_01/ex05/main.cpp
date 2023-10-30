/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 21:56:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	Harlito;

	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;
	Harlito.complain("DEBUG");
	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;
	Harlito.complain("INFO");
	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;
	Harlito.complain("WARNING");
	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;
	Harlito.complain("ERROR");
	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;
	Harlito.complain("X");
	std::cout << WHITE_C << "[ ... ]" << END_COLOR << std::endl;

	return (EXIT_SUCCESS);
}