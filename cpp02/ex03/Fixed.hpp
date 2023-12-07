/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:06 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 11:26:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;

		bool operator<( const Fixed& num ) const;
		bool operator>( const Fixed& num ) const;
		bool operator<=( const Fixed& num ) const;
		bool operator>=( const Fixed& num ) const;
		bool operator==( const Fixed& num ) const;
		bool operator!=( const Fixed& num ) const;

		Fixed operator+( const Fixed& num ) const;
		Fixed operator-( const Fixed& num ) const;
		Fixed operator*( const Fixed& num ) const;
		Fixed operator/( const Fixed& num ) const;

	private:
		int _rawBits;
		static const int _fractionalBits;
};


// << operator overload
// - it is c++ convention to return std::ostream&, allowing chaining of outupt operations
std::ostream& operator<<(std::ostream& out, const Fixed& n);

#endif
