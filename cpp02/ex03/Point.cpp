/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:16:13 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/13 09:18:36 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// default constructor
Point::Point(void): x(Fixed(0)), y(Fixed(0)) {}

// float constructor
Point::Point(const float f1, const float f2): x(Fixed(f1)), y(Fixed(f2)) {}

// copy constructor
Point::Point(const Point& other): x(other.getXCoord()), y(other.getYCoord()) {}

// copy assignment constructor
// - if you want to remove the const, cast the var to the data type w/o const (error)
// - you cannot change const variables, so just return *this in all cases
Point& Point::operator=(const Point& other) {
	if (this == &other)
		return *this;
	return *this;
}

// destructor
Point::~Point(void) {}

// getters
const Fixed Point::getXCoord(void) const {
	return this->x;
}

const Fixed Point::getYCoord(void) const {
	return this->y;
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Point& pt) {
	out << "x: " << pt.getXCoord() << ", y: " << pt.getYCoord();
	return (out);
}
