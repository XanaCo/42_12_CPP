/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/02/13 18:48:10 by ancolmen         ###   ########.fr       */
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

void PmergeMe::mergeVector(std::vector<int> &array, int left, int mid, int right) {
	
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;

	std::vector<int> Left(sizeLeft);
	std::vector<int> Right(sizeRight);

	for (int i = 0; i < sizeLeft; ++i)
		Left[i] = array[left + i];
	for (int i = 0; i < sizeRight; ++i)
		Right[i] = array[mid + 1 + i];

	int i = 0, j = 0, k = left;

	while (i < sizeLeft && j < sizeRight) 
	{
 		if (Left[i] <= Right[j])
		{
			array[k] = Left[i];
			i++;
		}
		else
		{
			array[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < sizeLeft)
	{
		array[k] = Left[i];
		i++;
		k++;
	}

	while (j < sizeRight)
	{
		array[k] = Right[j];
		j++;
		k++;
	}
}

void PmergeMe::mergeList(std::list<int> &list, std::list<int> &left, std::list<int> &right) {
	
	list.clear();
	std::list<int>::iterator lit = left.begin();
	std::list<int>::iterator rit = right.begin();

	while (lit != left.end() && rit != right.end())
	{
		if (*lit <= *rit)
		{
			list.push_back(*lit);
			++lit;
		}
		else
		{
			list.push_back(*rit);
			++rit;
		}
	}

	while (lit != left.end())
	{
		list.push_back(*lit);
		++lit;
	}

	while (rit != right.end())
	{
		list.push_back(*rit);
		++rit;
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int> &array, int left, int right) {

	if (left < right)
	{
		int mid = left + (right - left) / 2;
		fordJohnsonVector(array, left, mid);
		fordJohnsonVector(array, mid + 1, right);
		mergeVector(array, left, mid, right);
	}
}

void PmergeMe::fordJohnsonList(std::list<int> &list) {

	if (list.size() <= 1)
		return;

	std::list<int>::iterator it = list.begin();
	std::list<int> left;
	std::list<int> right;

	std::advance(it, list.size() / 2);
	
	left.splice(left.begin(), list, list.begin(), it);
	right.splice(right.begin(), list, it, list.end());

	fordJohnsonList(left);
	fordJohnsonList(right);
	mergeList(list, left, right);
}

// ************************************************************************** //
//	EXCEPTIONS
// ************************************************************************** //

PmergeMe::PmergeMeError::PmergeMeError(std::string errorMsg) throw() : _errorMsg(errorMsg) {}
				
PmergeMe::PmergeMeError::~PmergeMeError() throw() {}

const char *PmergeMe::PmergeMeError::what() const throw() {

	return _errorMsg.c_str();
}
