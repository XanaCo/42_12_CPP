/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 19:57:12 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define WHITE "\033[97;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[95;1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define END_COLOR "\033[0m"

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	
	ClapTrap(ClapTrap const &copie);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string		_name;
	int	_hit;
	int	_energy;
	int	_attack;

};

#endif
