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

	std::cout << WHITE <<  "Default contructor called" << END_COLOR <<  std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(Fixed const &src) {

	std::cout << WHITE <<  "Copy contructor called" << END_COLOR <<  std::endl;
	*this = src;
	return ;
}

/*DESTRUCTORS*/

Fixed::~Fixed(void) {

	std::cout << WHITE << "Destructor called" << END_COLOR << std::endl;
	return ;
}

/*MEMBER FUNCTIONS*/

Fixed &Fixed::operator=(Fixed const &rhs) {

	std::cout << WHITE << "Copy assignment operator called" << END_COLOR << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {

	std::cout << WHITE << "getRawBits member function called" << END_COLOR << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {

	this->_value = raw;
}