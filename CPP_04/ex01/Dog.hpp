/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 20:35:37 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

public:
	Dog(void);
	Dog(Dog const &copie);
	~Dog(void);

	Dog &operator=(Dog const &other);

	void makeSound(void) const;
	void setIdea(std::string idea, int index);
	Brain *getDogBrain(void) const;

private:
	Brain *_dogBrain;

};

#endif
