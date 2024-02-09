/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2023/11/06 16:29:32 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void display_test(std::string s) {

	std::cout << WHITE << "--- " << s << " ---" << END_COLOR << std::endl;
}

static void check(Point const a, Point const b, Point const c, Point const x, bool expected) {

	const bool result = bsp(a, b, c, x);
	
	const std::string color = (result == expected) ? GREEN : RED;
	const std::string verdict = (result == expected) ? "OK" : "KO";
	
	std::cout << color << x << " in " << a << b << c << ": " << verdict << " (expected " << expected
			  << " got " << result << ')' << END_COLOR << std::endl;
}

static void is_inside() {
	
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 3);

	display_test("INSIDE");
	
	check(a, b, c, Point(2, 1), true);
	check(a, b, c, Point(3, 1), true);
	check(a, b, c, Point(3, 2), true);
	check(a, b, c, Point(3.9f, 0.1f), true);
	check(a, c, b, Point(2, 1), true);
	check(a, c, b, Point(3, 1), true);
	check(a, c, b, Point(3, 2), true);
	check(a, c, b, Point(3.9f, 0.1f), true);
}

static void is_outside() {
	
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 3);

	display_test("OUTSIDE");
	
	check(a, b, c, Point(2, 2), false);
	check(a, b, c, Point(5, 2), false);
	check(a, b, c, Point(4.1f, 3.1f), false);
}

static void is_edge() {
	
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 3);

	display_test("EDGE");
	
	check(a, b, c, Point(1.0f, 0.75f), false);
	check(a, b, c, Point(2.0f, 1.5f), false);
	check(a, b, c, Point(3, 0), false);
	check(a, b, c, Point(4, 2), false);
}

static void is_corner() {
	
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 3);

	display_test("CORNER");
	
	check(a, b, c, Point(0, 0), false);
	check(a, b, c, Point(4, 0), false);
	check(a, b, c, Point(4, 3), false);
}

static void is_overlapping_triangle() {
	
	Point a(0, 0);
	Point b(4, 0);
	Point c(4, 3);

	display_test("TWO POINTS TRIANGLE");
	
	check(a, a, b, Point(2, 0), false);
	check(c, c, b, Point(4, 3), false);
	check(a, a, a, a, false);
}

static void is_linear_triangle() {
	
	Point a(0, 0);
	Point b(2, 1);
	Point c(4, 2);
	Point d = c;

	display_test("LINEAR TRIANGLE");
	
	check(a, b, d, Point(1.0f, 0.5f), false);
	check(a, b, d, Point(2, 1), false);
	check(a, b, d, Point(2, 2), false);
}

int main(void) {

	std::cout << std::endl;

	is_inside();
	is_outside();
	is_edge();
	is_corner();
	is_overlapping_triangle();
	is_linear_triangle();
	
	std::cout << std::endl;
}