/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:10:04 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/03 00:10:04 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

#pragma once

// iterator definition for addMultipleNumbers()
typedef std::vector<int>::iterator Iterator;

class Span {
    public:
        Span();
        Span( unsigned int N );
        Span( const Span& other );
        Span& operator=( const Span& other );
        ~Span();

        void addNumber( const long& num );
        void addMultipleNumbers( Iterator begin, Iterator end );
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        // extra methods:
        void printMinElement() const;
        void printMaxElement() const;
        void printSortedElements() const;

    private:
       unsigned int _maxN;
       std::vector<int> _elements;
};

/*
Exceptions:
1. when _maxN is reached
2. when there are either 0 / 1 elements, no span can be found
*/

class SpanException: public std::exception {
	public:
		SpanException( const std::string& errorMsg ): _errorMsg(errorMsg) {}
		virtual const char *what() const throw() {
			return (this->_errorMsg).c_str();
		}
		virtual ~SpanException() throw() {}

	private:
		const std::string _errorMsg;
};
