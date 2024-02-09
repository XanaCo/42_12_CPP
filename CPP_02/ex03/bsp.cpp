/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 16:31:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static int	calculate_side(Point const p1, Point const p2, Point const point) {
	
	int pt_x = point.get_x().getRawBits();
	int pt_y = point.get_y().getRawBits();
	int p1_x = p1.get_x().getRawBits();
	int p1_y = p1.get_y().getRawBits();
	int p2_x = p2.get_x().getRawBits();
	int p2_y = p2.get_y().getRawBits();

	return p1_x * p2_y - p2_x * p1_y + p2_x * pt_y - pt_x * p2_y + pt_x * p1_y - p1_x * pt_y;

}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	
	int s1, s2, s3;
	bool neg, pos;

	s1 = calculate_side(a, b, point);
	s2 = calculate_side(b, c, point);
	s3 = calculate_side(c, a, point);

	neg = (s1 < 0) && (s2 < 0) && (s3 < 0);
	pos = (s1 > 0) && (s2 > 0) && (s3 > 0);
	
	return (neg || pos);
}
