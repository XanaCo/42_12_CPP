/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/31 16:03:36 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

	bool operator>(Fixed const &other) const; // a(this)>other = TRUE or FALSE
	bool operator<(Fixed const &other) const; // a(this)<other = TRUE or FALSE
	bool operator>=(Fixed const &other) const; // a(this)>=other = TRUE or FALSE
	bool operator<=(Fixed const &other) const; // a(this)<=other = TRUE or FALSE
	bool operator==(Fixed const &other) const; // a(this)==other = TRUE or FALSE
	bool operator!=(Fixed const &other) const; // a(this)!=other = TRUE or FALSE

	Fixed operator+(Fixed const &other) const; // a(this)+other= c
	Fixed operator-(Fixed const &other) const; // a(this)-other = c
	Fixed operator*(Fixed const &other) const; // a(this)*other = c
	Fixed operator/(Fixed const &other) const; // a(this)/other = c

	Fixed &operator++(void); // ++a = this + 1
	Fixed operator++(int); // a++ = c + 1
	Fixed &operator--(void); // --a = this - 1
	Fixed operator--(int); // a-- = c - 1

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
