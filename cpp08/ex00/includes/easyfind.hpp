/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:21:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/01 15:21:09 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

#pragma once

class ElementNotFoundException: public std::exception {
    public:
        const char* what() const throw();
};

const char* ElementNotFoundException::what() const throw() {
    return URED "Error: Element not found in container" RESET;
};

template <typename T> 
int easyfind( T container, const int& target ) {
    // container.begin(), container.end(): returns iterator pointing to the beginning and end

    // find(): returns iterator to the first element found in the range [first, last)
    //         if the element is not found, return last

    // typename: tells the compiler to treat container::iterator as a type instead of a static 
    //           member / value
    // it is used for dependent type name, which is a type that depends on a template parameter
    typename T::iterator it = std::find(container.begin(), container.end(), target);

    if (it == container.end()) {
        throw ElementNotFoundException();
    }
    return std::distance(container.begin(), it);
};
