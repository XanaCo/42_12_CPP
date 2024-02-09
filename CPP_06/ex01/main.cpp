/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/19 19:38:50 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	uintptr_t	tmp;
	Data		one;
	Data		*two = NULL;
	
	one.alive = true;
	one.num = 42;
	one.str = "I want to be free";

	std::cout << "one address : " << &one << std::endl;
	std::cout << "one.alive : " << one.alive << std::endl;
	std::cout << "one.num : " << one.num << std::endl;
	std::cout << "one.str : " << one.str << std::endl;
	
	tmp = Serializer::serialize(&one);

	std::cout << "tmp address : " << &tmp << std::endl;
	std::cout << "tmp : " << tmp << std::endl;
	
	two = Serializer::deserialize(tmp);

	std::cout << "two address : " << &two << std::endl;
	std::cout << "two.alive : " << two->alive << std::endl;
	std::cout << "two.num : " << two->num << std::endl;
	std::cout << "two.str : " << two->str << std::endl;
	
	return (EXIT_SUCCESS);
}
