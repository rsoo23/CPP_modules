/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:09:49 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/03 00:09:49 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

Span::Span(): _maxN(0) {}

Span::Span( unsigned int N ): _maxN(N) {}

Span::Span( const Span& other ) {
    _maxN = other._maxN;
    _elements = other._elements;
}

Span& Span::operator=( const Span& other ) {
    if (this != &other) {
        _maxN = other._maxN;
        _elements = other._elements;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber( const long& num ) {
    if (num < INT_MIN || num > INT_MAX) {
        throw SpanException(URED "Exception: Number is out of the integer range" RESET);
    } else if (_elements.size() < _maxN) {
        std::cout << UGRN << num << " is added" RESET << std::endl;
        _elements.push_back(num);
    } else {
        throw SpanException(URED "Exception: Vector capacity is full" RESET);
    }
}

void Span::addMultipleNumbers( Iterator begin, Iterator end ) {
    _elements.insert(_elements.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
    size_t numOfElements = _elements.size();

    // checks the if the number of elements are valid
    if (numOfElements == 0) {
        throw SpanException(URED "Exception: Vector is empty, unable to find shortest span");
    } else if (numOfElements == 1) {
        throw SpanException(URED "Exception: Vector has only one element, unable to find shortest span");
    }

    // assign _elements to tempElements and sort it
    std::vector<int> tempElements = _elements;
    std::sort(tempElements.begin(),  tempElements.end());

    std::vector<unsigned int> differences(tempElements.size() - 1);
    // (n + 1) - n, where (n + 1) is from the range [tempElements.begin() + 1, tempElements.end()) and n starts at tempElements.begin()
    // output result to output iterator differences
    std::transform(tempElements.begin() + 1, tempElements.end(), tempElements.begin(), differences.begin(), std::minus<unsigned int>());
    return *std::min_element(differences.begin(), differences.end());
}

unsigned int Span::longestSpan() const {
    size_t numOfElements = _elements.size();

    // checks the if the number of elements are valid
    if (numOfElements == 0) {
        throw SpanException(URED "Exception: Vector is empty, unable to find longest span");
    } else if (numOfElements == 1) {
        throw SpanException(URED "Exception: Vector has only one element, unable to find longest span");
    }
    // assign _elements to tempElements and sort it
    std::vector<int> tempElements = _elements;
    std::sort(tempElements.begin(), tempElements.end());

    return tempElements.back() - tempElements.front();
}

void Span::printMinElement() const {
    std::cout << UCYN "Min: " << *std::min_element(_elements.begin(), _elements.end()) << RESET << std::endl;
}

void Span::printMaxElement() const {
    std::cout << UCYN "Max: " << *std::max_element(_elements.begin(), _elements.end()) << RESET << std::endl;
}

void Span::printSortedElements() const {
    std::vector<int> tempElements;

    tempElements = _elements;
    std::sort(tempElements.begin(), tempElements.end());
    std::cout << PURPLE "Sorted Elements: ";

    std::vector<int>::iterator it = tempElements.begin();
    while (it != tempElements.end()) {
        std::cout << *it << ", "; 
        it++;
    }
    std::cout << RESET << std::endl;
}


