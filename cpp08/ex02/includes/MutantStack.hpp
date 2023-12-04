/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:46:48 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/03 21:46:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"

#pragma once

template <typename T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack(): std::stack<T>() {};
        MutantStack( const MutantStack& other ): std::stack<T>(other) {};
        MutantStack& operator=( const MutantStack& other ) { if (this != &other) {*this = other;} return *this; };
		~MutantStack() {};

        // accesses std::stack's underlying container's iterator
        typedef typename std::stack<T>::container_type::iterator iterator;

        // std::stack has a member called 'c' which is its underlying container
        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };

    private:
       std::stack<T> _stack;
};
