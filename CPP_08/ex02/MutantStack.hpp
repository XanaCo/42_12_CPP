/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/31 19:13:36 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <cstdlib>
# include <stack>
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

template <typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &copy) : std::stack<T>(copy) {}
	virtual ~MutantStack() {}

	MutantStack	&operator=(MutantStack const &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return (std::stack<T>::c.begin()); }
	iterator end() { return (std::stack<T>::c.end()); }
	
};

#endif
