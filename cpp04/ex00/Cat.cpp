/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:25 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 19:38:16 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Cat::Cat(): Animal() {
	this->type = "Cat";
	std::cout << GREEN << "Cat Constructed" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED << "Cat Destructed" << RESET << std::endl;
}

Cat::Cat( const Cat& other ): Animal(other) {
	*this = other;
	std::cout << GREEN << "Cat Copied" << RESET << std::endl;
}

Cat& Cat::operator=( const Cat& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << GREEN << "Cat Assigned" << RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << BLUE << "MEOW" << RESET << std::endl;
}
