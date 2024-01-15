/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/12/21 19:43:15 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*::: CONSTRUCTORS :::*/

ScalarConverter::ScalarConverter() {

	if (PRINT)
	{
		std::cout << GREEN
					<< "Constructor: ScalarConverter created"
					<< END_COLOR << std::endl;
	}
}

/*::: DESTRUCTORS :::*/

ScalarConverter::~ScalarConverter() {

	if (PRINT)
	{
		std::cout << RED
				<< "Destructor: ScalarConverter destroyed"
				<< END_COLOR << std::endl;
	}
}

/*::: MEMBER FUNCTIONS :::*/

void ScalarConverter::convert(std::string value) {
	
	char *endptr = NULL;
	double nb;

	if (value.empty())
		return ;

	nb = strtod(value.c_str(), &endptr);
	std::string endstr(endptr);

	// std::cout << "Value = " << value << std::endl;
	// std::cout << "NB = " << nb << std::endl;
	// std::cout << "endptr = " << endptr << std::endl;

	if (value.size() == 1 && !isdigit(value[0]))
		convertChar(value);

	else if (isnan(nb) && (endstr.empty() || !endstr.compare("f") || !endstr.compare("F")))
		convertNan();

	else if (isinf(nb) && (endstr.empty() || !endstr.compare("f") || !endstr.compare("F")))
		convertInf(nb);

	else if (!endstr.compare("f") || !endstr.compare("F"))
		convertFloat(nb);

	else if (endstr.empty() && value.find(".") != std::string::npos)
		convertDouble(nb);

	else if (endstr.empty())
		convertInt(nb);

	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
	
	exit(EXIT_FAILURE);
}

void ScalarConverter::convertChar(std::string value) {

	std::cout << "--- we execute convChar ---" << std::endl;

	char c = value.c_str()[0];
	if (c > 32 && c < 126)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertInt(double n) {

	(void)n;
	std::cout << "we execute convInt" << std::endl;
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertFloat(double n) {

	(void)n;
	std::cout << "we execute convFloat" << std::endl;
	exit(EXIT_SUCCESS);
}

void ScalarConverter::convertDouble(double n) {

	(void)n;
	std::cout << "we execute convDouble" << std::endl;
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