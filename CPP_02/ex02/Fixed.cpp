/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/31 16:45:31 by ancolmen         ###   ########.fr       */
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

int Fixed::getRawBits(void) const {

	return this->_value;
}

void Fixed::setRawBits(int const raw) {

	this->_value = raw;
}

float Fixed::toFloat(void) const {

	return ((float)this->_value / (float)(1 << this->_staticvalue));
}

int Fixed::toInt(void) const {

	return (this->_value >> this->_staticvalue);
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {

	if (a > b)
		return b;
	return a;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {

	if (a > b)
		return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {

	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {

	if (a > b)
		return a;
	return b;
}

/*::: Operator Overloading ::: */

Fixed &Fixed::operator=(Fixed const &other) {

	this->_value = other.getRawBits(); 
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {

	o << rhs.toFloat();
	return o;
}

bool Fixed::operator>(Fixed const &other) const {
 
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const {
 
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const {
 
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const {
 
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const {
 
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const {
 
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const {

	Fixed result(this->toFloat() + other.toFloat());

	return result;
}

Fixed Fixed::operator-(Fixed const &other) const {

	Fixed result(this->toFloat() - other.toFloat());

	return result;
}

Fixed Fixed::operator*(Fixed const &other) const {

	Fixed result(this->toFloat() * other.toFloat());

	return result;
}

Fixed Fixed::operator/(Fixed const &other) const {

	if (!other.toFloat())
	{
		std::cerr << "Error: Division by zero not accepted" << std::endl;
		return 0;
	}
	
	Fixed result(this->toFloat() / other.toFloat());

	return result;
}

Fixed &Fixed::operator++(void) {

	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {

	Fixed	prev(*this);

	this->_value++;
	return prev;
}

Fixed &Fixed::operator--(void) {

	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {

	Fixed	prev(*this);

	this->_value--;
	return prev;
}
