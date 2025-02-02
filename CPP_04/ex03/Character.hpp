/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/15 15:05:41 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

//Concrete Class : Inherits from Interface ICharacter

class Character : public ICharacter {

public:
	Character(void);
	Character(std::string const name);
	Character(Character const &copy);
	~Character(void);

	Character &operator=(Character const &other);
	
	std::string const &getName(void) const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	AMateria *getMat(int idx);
	
private:
	AMateria *_inventory[4];
	std::string _name;

};

#endif
