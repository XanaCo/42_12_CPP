/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/31 16:33:45 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include "Point.hpp"

#define WHITE "\033[97;1m"
#define END_COLOR "\033[0m"

class Fixed {

public:
	Fixed(void);
	Fixed(int const d);
	Fixed(float const f);
	Fixed(Fixed const &copie);
	~Fixed(void);

	Fixed &operator=(Fixed const &other);

	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed static &min(Fixed &a, Fixed &b);
	Fixed static &max(Fixed &a, Fixed &b);
	Fixed static const &min(Fixed const &a, Fixed const &b);
	Fixed static const &max(Fixed const &a, Fixed const &b);

private:
	int static const	_staticvalue = 8;
	int					_value;

};

std::ostream &operator<<(std::ostream &o, Fixed const &other);

#endif
