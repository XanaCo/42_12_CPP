/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 20:46:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CONSTRUCTORS*/

Fixed::Fixed(void) {

	this->_value = 0;
	return ;
}

Fixed::Fixed(int const d) {

	this->_value = d << this->_staticvalue;
	return ;
}

Fixed::Fixed(float const f) {

	this->_value = roundf(f * (1 << this->_staticvalue));
	return ;
}

Fixed::Fixed(Fixed const &src) {

	*this = src;
	return ;
}

/*DESTRUCTORS*/

Fixed::~Fixed(void) {

	return ;
}

/*MEMBER FUNCTIONS*/

Fixed &Fixed::operator=(Fixed const &rhs) {

	this->_value = rhs.getRawBits(); 
	return *this;
}

int Fixed::getRawBits( void ) const {

	return this->_value;
}

void Fixed::setRawBits( int const raw ) {

	this->_value = raw;
}

float Fixed::toFloat(void) const {

	return ((float)this->_value / (float)(1 << this->_staticvalue));
}

int Fixed::toInt(void) const {

	return (this->_value >> this->_staticvalue);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {

	o << rhs.toFloat();
	return o;
}