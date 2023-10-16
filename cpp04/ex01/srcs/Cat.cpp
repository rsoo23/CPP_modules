/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:25 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:21:04 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << BGRN << "Cat Constructed" << RESET << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << BRED << "Cat Destructed" << RESET << std::endl;
}

Cat::Cat( const Cat& other ) {
	this->brain = new Brain(*(other.brain));
	std::cout << BGRN << "Cat Copied" << RESET << std::endl;
}

Cat& Cat::operator=( const Cat& other ) {
	if (this != &other) {
		this->type = other.type;

		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << BGRN << "Cat Assigned" << RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << BLUE << "MEOW" << RESET << std::endl;
}

Brain* Cat::getBrain() {
	return this->brain;
};
