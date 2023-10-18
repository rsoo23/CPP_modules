/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:19:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 19:38:49 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Dog::Dog(): Animal() {
	this->type = "Dog";
	std::cout << GREEN << "Dog Constructed" << RESET << std::endl;
}

Dog::~Dog() {
	std::cout << RED << "Dog Destructed" << RESET << std::endl;
}

Dog::Dog( const Dog& other ): Animal(other) {
	*this = other;
	std::cout << GREEN << "Dog Copied" << RESET << std::endl;
}

Dog& Dog::operator=( const Dog& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << GREEN << "Dog Assigned" << RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW << "WOOF WOOF" << RESET << std::endl;
}
