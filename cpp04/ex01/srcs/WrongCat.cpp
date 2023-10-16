/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:07:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 15:24:34 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

WrongCat::WrongCat(): WrongAnimal() {
	this->type = "WrongCat";
	this->brain = new Brain();
	std::cout << GREEN << "WrongCat Constructed" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	delete this->brain;
	std::cout << RED << "WrongCat Destructed" << RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ): WrongAnimal(other) {
	*this = other;
	std::cout << GREEN << "WrongCat Copied" << RESET << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	if (this != &other) {
		this->type = other.type;
		this->brain = other.brain;
	}
	std::cout << GREEN << "WrongCat Assigned" << RESET << std::endl;
	return *this;
}

Brain* WrongCat::getBrain() {
	return this->brain;
};

