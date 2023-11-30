/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:18:59 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/01 14:18:59 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

#pragma once

class Complex {
    public:
        Complex(): _real(0), _imaginary(0) {};
        Complex( const Complex& other ) { _real = other._real; _imaginary = other._imaginary; };
        Complex& operator=( const Complex& other ) { _real = other._real; _imaginary = other._imaginary; return *this; };
        // ~Complex();

        void set( int re, int im ) {_real = re; _imaginary = im; };
        int get_re() const { return this->_real; }
        int get_im() const { return this->_imaginary; }

    private:
        int _real;
        int _imaginary;
};

std::ostream& operator<<( std::ostream& o, const Complex& c ) {
    if (c.get_im() > 0) {
        o << c.get_re() << "+" << c.get_im() << "i";
    } else if (c.get_im() == 0) {
        o << c.get_re();
    } else if (c.get_im() < 0) {
        o << c.get_re() << c.get_im() << "i";
    }
    return o;
}
