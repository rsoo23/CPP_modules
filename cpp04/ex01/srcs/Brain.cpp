/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:39:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:39:34 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Brain::Brain() {
	std::cout << GREEN << "Brain Constructed" << RESET << std::endl;
}

Brain::~Brain() {
	std::cout << RED << "Brain Destructed" << RESET << std::endl;
}

Brain::Brain( const Brain& other ) {
	*this = other;
	std::cout << GREEN << "Brain Copied" << RESET << std::endl;
}

Brain& Brain::operator=( const Brain& other ) {
	if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
	}
	std::cout << GREEN << "Brain Assigned" << RESET << std::endl;
	return *this;
}
