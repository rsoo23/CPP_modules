/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:10:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/01 11:10:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

#pragma once

template <typename T> class Array {
    public:
        Array();
        Array( unsigned int n );
        Array( Array const& other );
        Array& operator=( Array const& other );
        ~Array();

        unsigned int size() const;
        T& operator[]( unsigned int index );

    private:
        T* _data;
        unsigned int _size;
};

template <typename T> Array<T>::Array() {
    this->_data = new T();
    this->_size = 0;
    std::cout << GREEN "Array with size 0 constructed" RESET << std::endl;
}

template <typename T> Array<T>::Array( unsigned int n ) {
    this->_data = new T[n];
    this->_size = n;
    std::cout << GREEN "Array with size " << n << " constructed" RESET << std::endl;
}

template <typename T> Array<T>::Array( Array const& other ) {
    this->_size = other._size;
    this->_data = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
    std::cout << CYAN "Array copied" RESET << std::endl;
}

template <typename T> Array<T>& Array<T>::operator=( Array const& other ) {
    if (this != &other) {
        delete[] this->_data;
        this->_size = other._size;
        this->_data = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_data[i] = other._data[i];
        }
    }
    std::cout << CYAN "Array assigned" RESET << std::endl;
    return *this;
}

template <typename T> Array<T>::~Array() {
    delete[] this->_data;
    std::cout << RED "Array destructed" RESET << std::endl;
}

template <typename T> unsigned int Array<T>::size() const {
    return this->_size;
}

template <typename T> T& Array<T>::operator[]( unsigned int n ) {
    if (n < this->_size) {
        return this->_data[n];
    } else {
        throw std::out_of_range("Index is out of range");
    }
}

template <typename T> std::ostream& operator<<( std::ostream& o, Array<T>& arr ) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        o << UPUR << "index " << i << ": " << arr[i] << RESET << std::endl;
    }
    return o;
}
