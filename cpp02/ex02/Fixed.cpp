/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/03 15:12:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

// constructor
Fixed::Fixed( void ): _rawBits(0) {}

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
	this->_rawBits = n << this->_fractionalBits;
}

// float constructor
// - converts float to fixed-point value
/*
ex:
3.65 = 11.101
11.101 * (1 << 8) = 11.101 * 1 0000 0000 = 0000 0001 1101 0000
integer part: 0000 0001
fractional part: 1101 0000
*/
Fixed::Fixed( const float n ) {
	this->_rawBits = (roundf(n * (1 << this->_fractionalBits)));
}

// copy constructor
Fixed::Fixed( const Fixed& other ) {
	*this = other;
}

// copy assignment constructor
Fixed& Fixed::operator=( const Fixed& other ) {
	if (this != &other) { 			// this is to prevent self-assignments
		this->setRawBits(other.getRawBits());
	}
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

// pre-increment overload
Fixed Fixed::operator++( void ) {
	++this->_rawBits;
	return *this;
}

// post-increment overload
Fixed Fixed::operator++( int ) {
	Fixed temp = *this;
	++this->_rawBits;
	return temp;
}

// pre-decrement overload
Fixed Fixed::operator--( void ) {
	--this->_rawBits;
	return *this;
}

// post-decrement overload
Fixed Fixed::operator--( int ) {
	Fixed temp = *this;
	--this->_rawBits;
	return temp;
}

// min overload (without const)
const Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	if (num1._rawBits < num2._rawBits)
		return num1;
	return num2;
}

// min overload (with const)
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	if (num1._rawBits < num2._rawBits)
		return num1;
	return num2;
}

// max overload (without const)
const Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	if (num1._rawBits > num2._rawBits)
		return num1;
	return num2;
}

// max overload (with const)
const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	if (num1._rawBits > num2._rawBits)
		return num1;
	return num2;
}

// member version, inside the class
// bool operator<(const NewType& rhs) const {
//     return val < rhs.val;
// }

// non-member version, outside the class
// bool operator<(const NewType& lhs, const NewType& rhs) {
//     return lhs.GetVal() < rhs.GetVal();
// }
