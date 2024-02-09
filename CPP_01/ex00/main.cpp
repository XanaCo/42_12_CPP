/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/29 17:07:04 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_01;
	
	std::cout << std::endl 
				<< "\033[97;1m(main) \033[0m"
				<< "We create a Zombie in the Heap with newZombie" << std::endl;
	new_01 = newZombie("Peter");
	std::cout << "\033[97;1m(main) \033[0m"
				<< "We control him inside the main" << std::endl;
	new_01->annouce();
	//we can still manipulate Peter here, keep him warm, make him do some stuff!
	std::cout << "\033[97;1m(main) \033[0m"
				<< "We destroy Peter when we want, we delete and free the memory, Peter is dynamic" << std::endl;
	delete new_01;
	
	std::cout << std::endl
				<< "\033[97;1m(main) \033[0m"
				<< "We create a Zombie in the Stack with randomChump" << std::endl;
	randomChump("Pedro");
	//Pedro will always be created and destroyed in randomChump!
	std::cout << "\033[97;1m(main) \033[0m"
				<< "We are back without possibility of control, nothing to free, Pedro was local" << std::endl << std::endl;

	return 0;
}