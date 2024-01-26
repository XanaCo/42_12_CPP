/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/26 15:28:14 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *array, int size, void(*f)(T const &block)) {

	if (size <= 0)
	{
		std::cerr << "Error : Wrong array size located in " << array << std::endl;
		return;
	}
	for (int i = 0; i < size; i++)
		(*f)(array[i]);
}

template<typename T>
void printBlock(T const &block) {

	std::cout << block << std::endl;
}

#endif
