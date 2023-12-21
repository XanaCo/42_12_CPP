/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 19:45:24 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter res;

		res.convert(argv[1]);
		
	}
	// 	./convert 0
	// char: Non displayable
	// int: 0
	// float: 0.0f
	// double: 0.0
	
	// ./convert nan
	// char: impossible
	// int: impossible
	// float: nanf
	// double: nan
	
	// ./convert 42.0f
	// char: '*'
	// int: 42
	// float: 42.0f
	// double: 42.0

	return 0;
}


