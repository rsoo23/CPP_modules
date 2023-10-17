/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:43:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 11:34:23 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria() {
	std::cout << GREEN << "AMateria Constructed" << RESET << std::endl;
}

AMateria::AMateria( std::string& const type ): type(type) {
	std::cout << GREEN << "AMateria Constructed with type: "<< type << RESET << std::endl;
}

AMateria::AMateria( const AMateria& other ) {
	*this = other;
	std::cout << GREEN << "AMateria Copied" << RESET << std::endl;
}

AMateria& AMateria::operator=( const AMateria& other ) {
	if (this != & other) {
		this->type = other.type;
	}
	std::cout << GREEN << "AMateria Assigned" << RESET << std::endl;
	return *this;
}

AMateria::~AMateria() {
	std::cout << RED << "AMateria Destructed" << RESET << std::endl;
}

std::string const& AMateria::getType() const {
	return this->type;
}
