/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 21:16:16 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# define WHITE "\033[97;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[95;1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define END_COLOR "\033[0m"

//Abstract Class

class AMateria {

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &copy);
	virtual ~AMateria(void);

	AMateria &operator=(AMateria const &other);

	std::string const &getType(void) const;
	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);

protected:
	std::string _type;

};

#endif
