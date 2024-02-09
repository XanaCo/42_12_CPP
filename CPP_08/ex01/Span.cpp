/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/31 18:25:50 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*::: CONSTRUCTORS :::*/

Span::Span(unsigned int const n) : _nMax(n) {

	if (PRINT)
		std::cout << GREEN << "Constructor: Span created" << END_COLOR << std::endl;
}

Span::Span(Span const &copy) : _nMax(copy._nMax) {

	_span.insert(copy._span.begin(), copy._span.end());

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
	
	std::set<int>::iterator it = _span.begin();
	int shorty = *(_span.end());

	while (++it != _span.end())
	{
		std::set<int>::iterator prev = it;
		std::advance(prev, -1);
		int currentSpan = *it - *prev;
		
		shorty = std::min(shorty, currentSpan);
	}

	return shorty;
}

int Span::longestSpan() const {

	if (_span.size() < 2)
		throw std::range_error("Error : Not enough elements for longestSpan");

	int longy = *(--_span.end()) - *(_span.begin());

	return longy;
}

