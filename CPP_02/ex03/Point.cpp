/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 16:07:19 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*CONSTRUCTORS*/

Point::Point(void) {

	return ;
}

Point::Point(Fixed const x, Fixed const y) {
	
	const_cast<Fixed&>(_x) = x;
	const_cast<Fixed&>(_y) = y;
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

	const_cast<Fixed&>(_x) = other._x;
	const_cast<Fixed&>(_y) = other._y;

	return *this;
}

std::ostream &operator<<(std::ostream &o, Point const &other) {

	o << '(' << other.get_x() << ',' << other.get_y() << ')';
	return o;
}

/*MEMBER FUNCTIONS*/

Fixed Point::get_x() const {
	
	return _x;
}

Fixed Point::get_y() const {

	return _y;
}