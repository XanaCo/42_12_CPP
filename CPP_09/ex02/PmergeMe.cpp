/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/13 14:48:00 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

PmergeMe::PmergeMe(int size, char **listNum) : _size(size - 1) {

	for (int i = 1; i < size; ++i)
	{
		std::string tmp(listNum[i]);
		
		if (tmp.find(DIGIT) != std::string::npos || tmp.empty()
			|| atoi(listNum[i]) < 0 || tmp.at(0) == '-')
			throw PmergeMeError("Error: wrong digit input");
		if (std::find(_array.begin(), _array.end(), atoi(listNum[i])) != _array.end())
			throw PmergeMeError("Error: doubles not permitted");
		_array.push_back(atoi(listNum[i]));
		_list.push_back(atoi(listNum[i]));
	}
}

PmergeMe::~PmergeMe() {}

// ************************************************************************** //
//	LA GET-SET
// ************************************************************************** //

std::vector<int> PmergeMe::getArray() const {

	return this->_array;
}

std::list<int> PmergeMe::getList() const {

	return this->_list;
}

int PmergeMe::getSize() const {

	return this->_size;
}

// template<typename Container>
// std::string PmergeMe::getType(Container const &container) {
	
// 	(void)container;
	
// 	if (typeid(Container) == typeid(std::vector<int>))
// 		return VECTOR;
		
// 	if (typeid(Container) == typeid(std::list<int>))
// 		return LIST;
		
// 	return "Unknown";
// }

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

// template<typename Container>
// void PmergeMe::time(Container container) {

// 	std::string cont;
	
// 	if (getType(container) == LIST)
// 		cont = LIST;
		
// 	if (getType(container) == VECTOR)
// 		cont = VECTOR;
		
// 	std::cout << "Time to process a range of "
// 		<< getSize() << " elements with " << cont << " : " << std::endl;
// }

// template<typename Container>
// void PmergeMe::sort(Container container) {
	
// 	(void)container;
// 	std::cout << "sorting time" << std::endl;
// }

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

PmergeMe::PmergeMeError::PmergeMeError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
PmergeMe::PmergeMeError::~PmergeMeError() throw() {}

const char *PmergeMe::PmergeMeError::what() const throw() {

	return _errorMsg.c_str();
}
