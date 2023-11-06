/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/31 16:46:00 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*CONSTRUCTORS*/

Point::Point(void) {

	return ;
}

Point::Point(Point const &src) {

	*this = src;
	return ;
}

/*DESTRUCTORS*/

Point::~Point(void) {

	return ;
}

/*::: Operator Overloading ::: */

Point &Point::operator=(Point const &other) {

	if (this == &other)
		return *this;
	// copy values from other into this //
	return *this;
}

/*MEMBER FUNCTIONS*/