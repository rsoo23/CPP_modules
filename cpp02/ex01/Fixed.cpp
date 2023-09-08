/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/10 00:28:46 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

// constructors
Fixed::Fixed( void ): _rawBits(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( const int n ) {
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	
}

Fixed::Fixed( const float n ) {
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	
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
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return (this->_rawBits);
}

// setter
void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

// converts fixed-point value -> floating point value
float Fixed::toFloat( void ) const {
	
}

// converts fixed-point value -> integer value
int   Fixed::toInt( void ) const {
	
}
