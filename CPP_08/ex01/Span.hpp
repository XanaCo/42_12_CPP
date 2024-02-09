/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/31 18:24:10 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iterator>
# include <cstdlib>
# include <set>
# include <list>
# include <deque>
# include <vector>
# include <exception>
# include <algorithm>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define WHITE "\033[37;1m"
# define END_COLOR "\033[0m"

# define PRINT true


class Span {

public:
	Span(unsigned int const n);
	Span(Span const &copy);
	~Span();
	
	unsigned int getnMax() const;
	std::set<int> getSpan() const;

	void addNumber(int numToAdd);
	int shortestSpan() const;
	int longestSpan() const;
	
	template <typename T>
	void addRange(T begin, T end) {

	if (_span.size() + std::distance(begin, end) > _nMax)
		throw std::range_error("Error : nMax atteinted");

	_span.insert(begin, end);
	
	}

private:
	Span	&operator=(Span const &other);

	unsigned int const _nMax;
	std::set<int> _span;

};

#endif
