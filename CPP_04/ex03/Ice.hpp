/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:29:16 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

//Concrete Class: Inherits from Abstract AMateria

class Ice : public AMateria {

public:
	Ice(void);
	Ice(Ice const &copy);
	~Ice(void);

	Ice &operator=(Ice const &other);
	
	AMateria *clone(void) const;
	void use(ICharacter &target);

};

#endif
