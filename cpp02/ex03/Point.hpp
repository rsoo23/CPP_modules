/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:16:15 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 23:15:34 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

class Point {
	public:
		Point( void );
		Point( const float f1, const float f2 );
		Point( const Point& other );
		Point& operator=( const Point& other );
		~Point( void );

		const Fixed getXCoord( void ) const;
		const Fixed getYCoord( void ) const;

	private:
		const Fixed x;
		const Fixed y;
};

// << operator overload
std::ostream& operator<<(std::ostream& out, const Point& pt);

#endif
