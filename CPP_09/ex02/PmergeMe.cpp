/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:16:05 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/14 17:37:53 by ancolmen         ###   ########.fr       */
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

// ************************************************************************** //
//	METHODS
// ************************************************************************** //

void PmergeMe::fordJohnsonVector(std::vector<int> &array) {

	if (array.size() <= 1)
		return;

	size_t i;
	std::vector<int> largerElements;
	
//Group into pairs and compare
	for (i = 0; i < array.size() - 1; i += 2)
	{
		if (array[i] > array[i + 1])
			largerElements.push_back(array[i]);
		else
			largerElements.push_back(array[i + 1]);
	}

	if (i == array.size() - 1)
		largerElements.push_back(array[i]);

//Sort recursively the larger elements
	fordJohnsonVector(largerElements);

//Insert the smallest at the start of the sorted sequence
	std::vector<int> sortedSequence;
	sortedSequence.push_back(array[0]);

//Insert reamainig elements into the sorted sequence
	for (size_t k = 1; k < array.size(); ++k)
	{
		if (array[k] < sortedSequence[0])
			sortedSequence.insert(sortedSequence.begin(), array[k]);
		else
		{
			std::vector<int>::iterator it = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), array[k]);
			sortedSequence.insert(it, array[k]);
		}
	}

	array = sortedSequence;
}

void PmergeMe::fordJohnsonList(std::list<int> &list) {

	if (list.size() <= 1)
		return;

	std::list<int> largerElements;
	std::list<int>::iterator it = list.begin();
	
//Group into pairs and compare
	while (it != list.end())
	{
	 	int firstElement = *it;
		++it;
		
		if (it != list.end())
		{
			int secondElement = *it;
			++it;
	
			if (firstElement > secondElement)
				largerElements.push_back(firstElement);
			else
				largerElements.push_back(secondElement);

		}
		else
			largerElements.push_back(firstElement);
	}

//Sort recursively the larger elements
	fordJohnsonList(largerElements);

//Insert the smallest at the start of the sorted sequence
	std::list<int> sortedSequence;
	sortedSequence.push_back(list.front());

//Insert reamainig elements into the sorted sequence
	for (std::list<int>::iterator it = ++list.begin(); it != list.end(); ++it)
	{
		if (*it < sortedSequence.front())
			sortedSequence.push_front(*it);
		else
		{
			std::list<int>::iterator insertPos = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), *it);
			sortedSequence.insert(insertPos, *it);
		}
	}

	list = sortedSequence;
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

PmergeMe::PmergeMeError::PmergeMeError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
PmergeMe::PmergeMeError::~PmergeMeError() throw() {}

const char *PmergeMe::PmergeMeError::what() const throw() {

	return _errorMsg.c_str();
}
