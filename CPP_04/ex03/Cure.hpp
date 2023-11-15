/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:29:13 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//Concrete Class: Inherits from Abstract AMateria

class Cure : public AMateria {

public:
	Cure(void);
	Cure(Cure const &copy);
	~Cure(void);

	Cure &operator=(Cure const &other);
	
	AMateria *clone(void) const;
	void use(ICharacter &target);

};

#endif
