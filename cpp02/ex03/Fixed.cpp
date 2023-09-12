/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 14:37:27 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

// constructor
Fixed::Fixed( void ): _rawBits(0) {}

// int constructor
Fixed::Fixed( const int n ) {
	this->_rawBits = n << this->_fractionalBits;
}

// float constructor
Fixed::Fixed( const float n ) {
	this->_rawBits = (roundf(n * (1 << this->_fractionalBits)));
}

// copy constructor
Fixed::Fixed( const Fixed& other ) {
	*this = other;
}

// copy assignment constructor
Fixed& Fixed::operator=( const Fixed& other ) {
	if (this != &other) 			// this is to prevent self-assignments
		this->setRawBits(other.getRawBits());
	return (*this);
}

// destructor
Fixed::~Fixed( void ) {}

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

// << operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& n) {
	out << n.toFloat();
	return (out);
}

// < operator overload
bool Fixed::operator<(const Fixed& num) const {
	return (this->_rawBits < num._rawBits);
}

// > operator overload
bool Fixed::operator>(const Fixed& num) const {
	return (this->_rawBits > num._rawBits);
}

// <= operator overload
bool Fixed::operator<=(const Fixed& num) const {
	return (this->_rawBits <= num._rawBits);
}

// >= operator overload
bool Fixed::operator>=(const Fixed& num) const {
	return (this->_rawBits >= num._rawBits);
}

// == operator overload
bool Fixed::operator==(const Fixed& num) const {
	return (this->_rawBits == num._rawBits);
}

// != operator overload
bool Fixed::operator!=(const Fixed& num) const {
	return (this->_rawBits != num._rawBits);
}

// + operator overload
Fixed Fixed::operator+(const Fixed& num) const {
	return Fixed(this->toFloat() + num.toFloat());
}

// - operator overload
Fixed Fixed::operator-(const Fixed& num) const {
	return Fixed(this->toFloat() - num.toFloat());
}

// * operator overload
Fixed Fixed::operator*(const Fixed& num) const {
	return Fixed(this->toFloat() * num.toFloat());
}

// / operator overload
Fixed Fixed::operator/(const Fixed& num) const {
	return Fixed(this->toFloat() / num.toFloat());
}
