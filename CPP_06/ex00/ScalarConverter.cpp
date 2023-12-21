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

	std::cout << GREEN
				<< "Constructor: ScalarConverter created"
				<< END_COLOR << std::endl;
}

/*::: DESTRUCTORS :::*/

ScalarConverter::~ScalarConverter() {

	std::cout << RED
			<< "Destructor: ScalarConverter destroyed"
			<< END_COLOR << std::endl;
}

/*::: MEMBER FUNCTIONS :::*/

void ScalarConverter::convert(std::string value) {
	
	std::cout << "char : " << dynamic_cast<char>(value) << std::endl;
	return ;
}