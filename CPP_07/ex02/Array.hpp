/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/23 21:23:53 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {

public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const &copy);
	~Array();
	
	Array<T> &operator=(Array<T> const &other);
	T &operator[](unsigned int pos);
	
	unsigned int size();

	class OutOfBoundaries : public std::exception {

		public:
			const char *what() const throw();
	};

	class AllocationFailed : public std::exception {

		public:
			const char *what() const throw();
	};

private:
	T *_array;
	unsigned int const _size;

};

# include "Array.tpp"
#endif
