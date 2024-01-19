/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/19 19:34:40 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <climits>
# include <cfloat>
# include <cmath>
# include <math.h>

# define B_RED "\033[91;1m"
# define B_GREEN "\033[92;1m"
# define B_YELLOW "\033[93;1m"
# define B_BLUE "\033[94;1m"
# define B_MAGENTA "\033[95;1m"
# define B_CYAN "\033[96;1m"
# define B_WHITE "\033[97;1m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

class ScalarConverter {

public:
	~ScalarConverter();
	
	static void convert(std::string value);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter	&operator=(ScalarConverter const &other);

	static void convertChar(std::string value);
	static void convertInt(double n);
	static void convertFloat(double n, std::string value);
	static void convertDouble(double n, std::string value);
	static void convertInf(double n);
	static void convertNan();
};

#endif
