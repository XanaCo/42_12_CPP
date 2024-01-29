/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/29 16:43:45 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <algorithm>
# include <iterator>

template<typename T>
typename T::const_reference easyfind(T const &container, int element) {
	
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), element);

	if (it == container.end())
		throw std::range_error("Error : Element not found in range");

	return *it;
}


#endif
