/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/03 08:58:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

// constructor
Fixed::Fixed( void ): _rawBits(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// int constructor
// - converts int to fixed-point value
/*
ex: 
12 = 0000 1100
0000 1100 << fractionalBits = 0000 1100 << 8 = 0000 1100 0000 0000
integer part: 0000 1100
fractional part: 0000 0000
*/
Fixed::Fixed( const int n ) {
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->_rawBits = n << this->_fractionalBits;
}

// float constructor
// - converts float to fixed-point value
/*
ex:
3.625 = 11.101
11.101 * (1 << 8) = 11.101 * 1 0000 0000 = 0000 0001 1101 0000
integer part: 0000 0001 
fractional part: 1101 0000
*/
Fixed::Fixed( const float n ) {
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	this->_rawBits = (roundf(n * (1 << this->_fractionalBits)));
}

// copy constructor
Fixed::Fixed( const Fixed& other ) {
	std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

// copy assignment constructor
Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) { 			// this is to prevent self-assignments
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

// destructor
Fixed::~Fixed( void ) {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

// getter
int Fixed::getRawBits( void ) const {
	return (this->_rawBits);
}

// setter
void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

// converts fixed-point value -> floating point value
float Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

// converts fixed-point value -> integer value
int   Fixed::toInt( void ) const {
	return (this->_rawBits >> _fractionalBits);
}

// << operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& n) {
	out << n.toFloat();
	return (out);
}
