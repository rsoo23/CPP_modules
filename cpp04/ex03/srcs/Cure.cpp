/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:22:54 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 11:07:46 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

Cure::Cure(): type("cure") {
	std::cout << GREEN << "Cure Constructed" << RESET << std::endl;
}

Cure::~Cure() {
	std::cout << RED << "Cure Destructed" << RESET << std::endl;
}

Cure::Cure( const Cure& other ) {
	*this = other;
	std::cout << GREEN << "Cure Copied" << RESET << std::endl;
}

Cure& Cure::operator=( const Cure& other ) {
	if (this != &other) {	
		this->type = other.type;
	}
	std::cout << GREEN << "Cure Assigned" << RESET << std::endl;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use( ICharacter& target ) {
	std::cout << UPUR << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
