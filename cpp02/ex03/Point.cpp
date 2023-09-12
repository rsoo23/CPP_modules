/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:16:13 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 23:32:36 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// default constructor
Point::Point(void): x(0), y(0) {}

// float constructor
Point::Point(const float f1, const float f2): x(f1), y(f2) {}

// copy constructor
Point::Point(const Point& other) {
	*this = other;
}

// copy assignment constructor
// - if you want to remove the const, cast the var to the data type w/o const
Point& Point::operator=(const Point& other) {
	if (this != &other) {
		(Fixed)this->x = other.getXCoord();
		(Fixed)this->y = other.getYCoord();
	}
	return *this;	
}

// destructoru
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
	out << "x: hi " << pt.getXCoord() << ", y: " << pt.getYCoord();
	return (out);
}
