/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:06 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/03 08:21:38 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed( void );
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _rawBits;
		static const int _fractionalBits;
};

#endif
