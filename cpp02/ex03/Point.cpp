/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:16:13 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 15:47:24 by rsoo             ###   ########.fr       */
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
Point& Point::operator=(const Point& other) {
	if (this != &other) {
		this->set_x_coord(other.get_x_coord());
		this->set_y_coord(other.get_y_coord());
	}
	return *this;	
}

// getters
const Fixed Point::get_x_coord(void) const {
	return this->x;
}

const Fixed Point::get_y_coord(void) const {
	return this->y;
}
