/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:43:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 19:37:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal() {
	this->type = "no type";
	std::cout << GREEN << "Animal Constructed" << RESET << std::endl;
}

Animal::Animal( std::string type ) {
	this->type = type;
	std::cout << GREEN << "Animal Constructed with type: " << RESET << this->type << std::endl;
}

Animal::~Animal() {
	std::cout << RED << "Animal Destructed" << RESET << std::endl;
}

Animal::Animal( const Animal& other ) {
	*this = other;
	std::cout << GREEN << "Animal Copied" << RESET << std::endl;
}

Animal& Animal::operator=( const Animal& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << GREEN << "Animal Assigned" << RESET << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << CYAN << "what does the animal say?" << RESET << std::endl;
}
