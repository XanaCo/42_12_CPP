/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/29 19:02:34 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iterator>
# include <set>

class Span {

public:
	Span(unsigned int const n);
	Span(Span const &copy);
	~Span();
	
	Span	&operator=(Span const &other);
	
	//addNumber(int numToAdd);
	//shortestSpan();
	//longestSpan();

	//exceptions : empty || onlyOne

private:
	unsigned int const _nMax;
	std::set<int> _span;

};

#endif
