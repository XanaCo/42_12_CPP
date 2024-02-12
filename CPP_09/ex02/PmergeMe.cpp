/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/12 19:28:35 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ************************************************************************** //
//	CONSTRUCTOR / DESTRUCTOR
// ************************************************************************** //

PmergeMe::PmergeMe(int size, char **listNum) : _size(size) {

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

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

std::string PmergeMe::getType() {
	
	return "TYPE tofind";
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

PmergeMe::PmergeMeError::PmergeMeError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
PmergeMe::PmergeMeError::~PmergeMeError() throw() {}

const char *PmergeMe::PmergeMeError::what() const throw() {

	return _errorMsg.c_str();
}
