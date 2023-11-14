/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/14 22:02:30 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

//Concrete Class : Inherits from Interface IMateriaSource

class MateriaSource : public IMateriaSource {

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &copy);
	~MateriaSource(void);

	MateriaSource &operator=(MateriaSource const &other);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_inventory[4];

};

#endif
