/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:06 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/10 00:44:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

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
		int   toInt( void ) const;

	private:
		int _rawBits;
		static const int _fractionalBits;
};


// << operator overload
// - it is c++ convention to return std::ostream&, allowing chaining of outupt operations
std::ostream& Fixed::operator<<(std::ostream& out, const Fixed& n) {
	out << n.toFloat();
	return (out);
}

#endif
