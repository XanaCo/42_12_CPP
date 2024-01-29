/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/29 23:38:29 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*::: CONSTRUCTORS :::*/

Span::Span(unsigned int const n) : _nMax(n) {

	if (PRINT)
		std::cout << GREEN << "Constructor: Span created" << END_COLOR << std::endl;
}

Span::Span(Span const &copy) : _nMax(copy._nMax) {


//copy _span 

	if (PRINT)
		std::cout << GREEN << "Constructor: Span copy created" << END_COLOR << std::endl;
	
}

/*::: DESTRUCTORS :::*/

Span::~Span() {

	if (PRINT)
		std::cout << RED << "Destructor: Span destroyed" << END_COLOR << std::endl;

}

/*::: ACCESSORS :::*/

unsigned int Span::getnMax() const {

	return this->_nMax;
}

std::set<int> Span::getSpan() const {

	return this->_span;
}

/*::: MEMBER FUNCTIONS :::*/

void Span::addNumber(int numToAdd) {

	if (_span.size() == this->_nMax)
		throw std::range_error("Error : nMax atteinted");

	_span.insert(numToAdd);
}

int Span::shortestSpan() const {
	
	if (_span.size() < 2)
		throw std::range_error("Error : Not enough elements for shortestSpan");
	
	int shorty;
	std::set<int>::iterator it;
	
	for (it = _span.begin(); it != _span.end(); it++)
		shorty = *(_span.upper_bound(*it));
	
	//shorty = *(_span.end()) - shorty;

	return shorty;
}

int Span::longestSpan() const {

	if (_span.size() < 2)
		throw std::range_error("Error : Not enough elements for longestSpan");
	
	int longy;
	std::set<int>::iterator it;

	for (it = _span.begin(); it != _span.end(); it++)
		longy = *(_span.lower_bound(*it));

	longy = longy - *(_span.begin());

	return longy;
}

//function range a faire
