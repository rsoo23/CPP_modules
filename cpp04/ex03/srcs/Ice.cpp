/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:09:49 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 14:33:01 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

Ice::Ice(): AMateria("ice") {
	std::cout << GREEN << "Ice Constructed" << RESET << std::endl;
}

Ice::~Ice() {
	std::cout << RED << "Ice Destructed" << RESET << std::endl;
}

Ice::Ice( const Ice& other ) {
	*this = other;
	std::cout << GREEN << "Ice Copied" << RESET << std::endl;
}

Ice& Ice::operator=( const Ice& other ) {
	if (this != &other) {	
		this->type = other.type;
	}
	std::cout << GREEN << "Ice Assigned" << RESET << std::endl;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use( ICharacter& target ) {
	std::cout << UCYN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
