/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/13 21:48:21 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"

# define IDEAS 5

class Brain {

public:
	Brain(void);
	Brain(Brain const &copie);
	~Brain(void);

	Brain &operator=(Brain const &other);

	std::string getIdea(int index) const;
	void setIdea(std::string &idea, int index);

private:
	std::string _ideas[IDEAS];

};

#endif
