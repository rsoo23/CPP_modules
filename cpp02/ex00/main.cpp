/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/28 13:43:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

// Expected Output:

// Default constructor called        [Fixed a]

// Copy constructor called           [Fixed b( a )]
// Copy assignment operator called   [*this = other]
// getRawBits member function called 

// Default constructor called        [Fixed c]
// Copy assignment operator called   [c = b]
// getRawBits member function called

// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0

// Destructor called
// Destructor called
// Destructor called
