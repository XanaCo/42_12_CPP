/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/22 14:44:57 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*::: CONSTRUCTORS :::*/

ScalarConverter::ScalarConverter() {}

/*::: DESTRUCTORS :::*/

ScalarConverter::~ScalarConverter() {}

/*::: MEMBER FUNCTIONS :::*/

void ScalarConverter::convert(std::string value) {
	
	char *endptr = NULL;
	double nb;

	if (value.empty())
		return ;

	nb = strtod(value.c_str(), &endptr);
	std::string endstr(endptr);

	if (value.size() == 1 && !isdigit(value[0]))
		convertChar(value);

	else if (isnan(nb) && (endstr.empty() || !endstr.compare("f") || !endstr.compare("F")))
		convertNan();

	else if (isinf(nb) && (endstr.empty() || !endstr.compare("f") || !endstr.compare("F")))
		convertInf(nb);

	else if (!endstr.compare("f") || !endstr.compare("F"))
		convertFloat(nb, value);

	else if (endstr.empty() && value.find(".") != std::string::npos)
		convertDouble(nb, value);

	else if (endstr.empty())
		convertInt(nb);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	
	exit(EXIT_FAILURE);
}

void ScalarConverter::convertChar(std::string value) {

	char c = value.c_str()[0];

	if (c > 32 && c < 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;

	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertInt(double n) {

	if (n > INT_MAX || n < INT_MIN)
	{
		std::cout << "char: impossible, Int overflow" << std::endl;
		std::cout << "int: impossible, Int overflow" << std::endl;
		std::cout << "float: impossible, Int overflow" << std::endl;
		std::cout << "double: impossible, Int overflow" << std::endl;
	}
	else
	{
		int num = static_cast<int>(n);

		if (num > 32 && num < 126)
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		std::cout << "int: " << num << std::endl;
		std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertFloat(double n, std::string value) {

	if (n > FLT_MAX || n < FLT_MIN)
	{
		std::cout << "char: impossible, float overflow" << std::endl;
		std::cout << "int: impossible, float overflow" << std::endl;
		std::cout << "float: impossible, float overflow" << std::endl;
		std::cout << "double: impossible, float overflow" << std::endl;
	}
	else
	{
		float num = static_cast<float>(n);
		int prec = value.size() - value.find('.') - 2;
	
		if (num > 32 && num < 126)
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << std::setprecision(prec) << std::setiosflags(std::ios::fixed) << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertDouble(double n, std::string value) {

	if (n > DBL_MAX || n < DBL_MIN)
	{
		std::cout << "char: impossible, double overflow" << std::endl;
		std::cout << "int: impossible, double overflow" << std::endl;
		std::cout << "float: impossible, double overflow" << std::endl;
		std::cout << "double: impossible, double overflow" << std::endl;
	}
	else
	{
		int prec = value.size() - value.find('.') - 1;
	
		if (n > 32 && n < 126)
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		
		std::cout << "int: " << static_cast<int>(n) << std::endl;
		std::cout << std::setprecision(prec) << std::setiosflags(std::ios::fixed) << "float: " << n << "f" << std::endl;
		std::cout << "double: " << n << std::endl;
	}
	
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertNan() {

	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;

	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertInf(double n) {

	if (n < 0)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}

	exit(EXIT_SUCCESS);
}