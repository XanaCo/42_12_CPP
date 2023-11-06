/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 22:45:26 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# define HIT 1
# define MAX_HIT 2
# define ENERGY 3
# define MAX_ENERGY 4
# define ATTACK 5

class DiamondTrap : public FragTrap, public ScavTrap {

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &copie);
	~DiamondTrap(void);

	DiamondTrap &operator=(DiamondTrap const &other);
	
	void whoAmI(void);
	int get_value(int index);

private:
	std::string _name;
};

#endif
