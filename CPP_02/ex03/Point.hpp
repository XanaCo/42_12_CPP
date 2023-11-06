/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 16:01:27 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

class Point {

private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point(void);
	Point(Fixed const x, Fixed const y);
	Point(Point const &copie);
	~Point(void);

	Point &operator=(Point const &other);
	Fixed get_x() const;
	Fixed get_y() const;

};

std::ostream &operator<<(std::ostream &o, Point const &other);

#endif
