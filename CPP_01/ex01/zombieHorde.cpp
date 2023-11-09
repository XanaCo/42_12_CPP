/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 17:54:42 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde( int N, std::string name ) {
	
	int	i = -1;
	
	if (N <= 0 || N >= MAX)
	{
		std::cout << "wrong number of Zombies (0 - INT_MAX)" << std::endl;
		return (NULL);
	}

	Zombie* horde = new Zombie[N];
	
	while (++i < N)
		horde[i].set_name(name);
	
	return horde;
}
