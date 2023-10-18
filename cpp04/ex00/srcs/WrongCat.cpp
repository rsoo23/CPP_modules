/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:07:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 20:10:22 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

WrongCat::WrongCat(): WrongAnimal() {
	this->type = "WrongCat";
	std::cout << GREEN << "WrongCat Constructed" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat Destructed" << RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ): WrongAnimal(other) {
	*this = other;
	std::cout << GREEN << "WrongCat Copied" << RESET << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << GREEN << "WrongCat Assigned" << RESET << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << BLUE << "WOEM " << RESET << std::endl;
}
