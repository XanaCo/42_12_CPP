/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/31 17:15:21 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define WHITE "\033[97;1m"
#define END_COLOR "\033[0m"

class Point {

public:
	Point(void);
	Point(Fixed const x, Fixed const y);
	Point(Point const &copie);
	~Point(void);

	Point &operator=(Point const &other);

private:
	Fixed const	_x;
	Fixed const	_y;

};

#endif
