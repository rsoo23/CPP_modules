/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:21:38 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/30 23:21:38 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

#ifndef ITER_HPP
#define ITER_HPP

template<typename T> void print_square( T const& n ) {
    std::cout << n << " squared is: " << n * n << std::endl;
}

template<typename T> void iter( T arr[], int arr_len, void (*func)(T const&) ) {
    for (int i = 0; i < arr_len; i++) {
        func(arr[i]);
    }
}

class Awesome {
    public:
        Awesome( void ) : _n( 42 ) { return; }
        int get( void ) const { return this->_n; }

    private:
        int _n;
};

std::ostream& operator<<( std::ostream& o, Awesome const& rhs ) { o << rhs.get(); return o; }

template<typename T> void print( T const& x ) { std::cout << x << std::endl; return; }

#endif
