/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:02:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 20:11:46 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

WrongAnimal::WrongAnimal() {
	this->type = "no type";
	std::cout << GREEN << "WrongAnimal Constructed" << RESET << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) {
	this->type = type;
	std::cout << GREEN << "WrongAnimal Constructed with type: " << RESET << this->type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal Destructed" << RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
	*this = other;
	std::cout << GREEN << "WrongAnimal Copied" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << GREEN << "WrongAnimal Assigned" << RESET << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << CYAN << "?yas lamina eht seod tahw" << RESET << std::endl;
}

