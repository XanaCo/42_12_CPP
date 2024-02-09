/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/26 17:19:25 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/*::: CONSTRUCTORS :::*/

template<typename T>
Array<T>::Array() : _size(0) {
	
	this->_array = new T[this->_size];
	if (!this->_array)
		throw AllocationFailed();
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	
	if (this->_size < 0)
		throw OutOfBoundaries();

	this->_array = new T[this->_size];

	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = 0;
	
	if (!this->_array)
		throw AllocationFailed();
	
}

template<typename T>
Array<T>::Array(Array<T> const &copy) : _size(copy._size) {

	this->_array = new T[this->_size];
	if (!this->_array)
		throw AllocationFailed();
	
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
	
}

/*::: DESTRUCTORS :::*/

template<typename T>
Array<T>::~Array() {

	delete[] _array;
}

/*::: Operator Overloading ::: */

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other) {

	if (this != &other)
	{
		this->_size = other._size;
	
		if (this->_array)
			delete[] this->_array;

		this->_array = new T[this->_size];
		if (!this->_array)
			throw AllocationFailed();
	
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int pos) const {

	if (pos < 0 || pos >= this->_size)
		throw OutOfBoundaries();

	return this->_array[pos];
}

/*::: MEMBER FUNCTIONS :::*/

template<typename T>
unsigned int Array<T>::size() {

	return this->_size;
}

/*::: EXCEPTIONS :::*/

template<typename T>
const char *Array<T>::OutOfBoundaries::what() const throw() {
	
	return "Error : Index Out of Scope";
}

template<typename T>
const char *Array<T>::AllocationFailed::what() const throw() {
	
	return "Error : Creation of Array Failed";
}

#endif