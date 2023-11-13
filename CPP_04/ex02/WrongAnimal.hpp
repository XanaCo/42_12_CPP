/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:48:45 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define WHITE "\033[97;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[95;1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define END_COLOR "\033[0m"

class WrongAnimal {

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &copie);
	~WrongAnimal(void);

	WrongAnimal &operator=(WrongAnimal const &other);

	void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string	type;

};

#endif
