/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/22 14:47:55 by ancolmen         ###   ########.fr       */
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
