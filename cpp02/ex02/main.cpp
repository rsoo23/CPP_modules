/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/03 15:16:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(2);
	Fixed const d(2);
	
	// from pdf
	std::cout << YELLOW << "Pre and post-increment: " << std::endl;
	std::cout << PURPLE << "a: " << a << std::endl;
	std::cout << CYAN << "++a: " << ++a << std::endl;
	std::cout << PURPLE << "a: " << a << std::endl;
	std::cout << CYAN << "a++: " << a++ << std::endl;
	std::cout << PURPLE << "a: " << a << RESET << std::endl << std::endl;

	std::cout << YELLOW << "Pre and post-decrement: " << std::endl;
	std::cout << PURPLE << "a: " << a << std::endl;
	std::cout << CYAN << "--a: " << --a << std::endl;
	std::cout << PURPLE << "a: " << a << std::endl;
	std::cout << CYAN << "a--: " << a-- << std::endl;
	std::cout << PURPLE << "a: " << a << RESET << std::endl << std::endl;

	std::cout << YELLOW << "Addition: " << RESET  << "b = " << b << ", c = " << c << std::endl;
	std::cout << PURPLE << "b + c: " << b + c << std::endl << std::endl;

	std::cout << YELLOW << "Subtraction: " << RESET << "b = " << b << ", c = " << c << std::endl;
	std::cout << PURPLE << "b - c: " << b - c << std::endl << std::endl;

	std::cout << YELLOW << "Multiplication: " << RESET << "b = " << b << ", c = " << c << std::endl;
	std::cout << PURPLE << "b * c: " << b * c << std::endl << std::endl;

	std::cout << YELLOW << "Division: " << RESET << "b = " << b << ", c = " << c << std::endl;
	std::cout << PURPLE << "b / c: " << b / c << std::endl;
	std::cout << YELLOW << "Division by 0: " << RESET << "a = " << a << ", b = " << b << std::endl;
	std::cout << PURPLE << "b / a: " << b / a << std::endl << std::endl;

	std::cout << YELLOW << "Max function: " << RESET << "b = " << b << ", c = " << c << std::endl;
	std::cout << GREEN << "max(b, c): b = " << Fixed::max( a, b ) << std::endl << std::endl;

	std::cout << YELLOW << "Min function: " << RESET << "b = " << b << ", c = " << c << std::endl;
	std::cout << GREEN << "min(b, c): " << Fixed::min( c, b ) << std::endl << std::endl;

	std::cout << YELLOW << "Less than: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << RED << "b < c: " << (b < c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << RED << "c < d: " << (c < d) << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << GREEN << "c < b: " << (c < b) << std::endl << std::endl;

	std::cout << YELLOW << "More than: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << GREEN << "b > c: " << (b > c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << RED << "c > d: " << (c > d) << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << RED << "c > b: " << (c > b) << std::endl << std::endl;

	std::cout << YELLOW << "Less than or equal to: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << RED << "b <= c: " << (b <= c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << GREEN << "c <= d: " << (c <= d) << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << GREEN << "c <= b: " << (c <= b) << std::endl << std::endl;

	std::cout << YELLOW << "More than or equal to: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << GREEN << "b >= c: " << (b >= c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << GREEN << "c >= d: " << (c >= d) << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << RED << "c >= b: " << (c >= b) << std::endl << std::endl;
	
	std::cout << YELLOW << "Equal to: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << RED << "b == c: " << (b == c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << GREEN << "c == d: " << (c == d) << RESET << std::endl << std::endl;
	
	std::cout << YELLOW << "Not equal to: " << RESET << std::endl;
	std::cout << "c = 2, b = 10.1016:	" << GREEN << "b != c: " << (b != c) << RESET << std::endl;
	std::cout << "c = 2, d = 2:		" << RED << "c != d: " << (c != d) << RESET << std::endl;
	
	return 0;
}

// the reason why ++a increases by 0.00390625 is because it represents 1/256 which is the 
// smallest graduation in a fixed point number with 9 fractional bits
