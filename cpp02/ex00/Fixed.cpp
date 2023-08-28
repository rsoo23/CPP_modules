/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/28 13:37:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_bits = 8;

Fixed::Fixed( void ): _rawValue(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other) { 			// this is to prevent self-assignments
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return (this->_rawValue);
}

void Fixed::setRawBits( int const raw ) {
	this->_rawValue = raw;
}
