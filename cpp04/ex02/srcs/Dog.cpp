/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:19:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:51:05 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << UGRN << "Dog Constructed" << RESET << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << URED << "Dog Destructed" << RESET << std::endl;
}

Dog::Dog( const Dog& other ) {
	this->brain = new Brain(*(other.brain));
	std::cout << UGRN << "Dog Copied" << RESET << std::endl;
}

Dog& Dog::operator=( const Dog& other ) {
	if (this != &other) {
		this->type = other.type;

		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << UGRN << "Dog Assigned" << RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << YELLOW << "WOOF WOOF" << RESET << std::endl;
}

Brain* Dog::getBrain() {
	return this->brain;
};
