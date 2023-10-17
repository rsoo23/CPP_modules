/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 12:04:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

Character::Character(): {
	for (int i = 0; i < 4; i++) {
		this->_slot[i] = nullptr;
	}
	for (int i = 0; i < 100; i++) {
		this->_trash[i] = nullptr;
	}
	std::cout << GREEN << "Character Constructed" << RESET << std::endl;
}

Character::~Character() {
	int i = 0;

	while (this->_slot[i]) {
		delete this->_slot[i];
		i++;
	}
	std::cout << RED << "Character Destructed" << RESET << std::endl;
}

Character::Character( const Character& other ) {
	*this = other;
	std::cout << GREEN << "Character Copied" << RESET << std::endl;
}

Character& Character::operator=( const Character& other ) {
	if (this != &other) {	
		this->type = other.type;
	}
	std::cout << GREEN << "Character Assigned" << RESET << std::endl;
	return *this;
}

std::string const& Character::getName() const {
	return this->_name;
}

void Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++) {
		if (!this->_slot[i]) {
			this->_slot[i] = m->clone();
			std::cout << UYEL << m->getType() << " is equipped to _slot " << i << RESET << std::endl;
			return ;
		}
	}
	std::cout << URED << "Error: Unable to equip Materia, inventory is full" << RESET std::endl;
}

/*
Cases:
- out of range
- _slot is empty
- _slot is equipped
*/
void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3) {
		std::cout << URED << "Error: Unable to unequip Materia, index is out of range" << RESET std::endl;
	} else if (!this->_slot[idx]) {
		std::cout << URED << "Error: Unable to unequip Materia, the _slot is already empty" << RESET std::endl;
	} else {
		
		this->_slot[idx] = nullptr;
	}
}

void Character::use( int idx, Character& target ) {
	if (idx < 0 || idx > 3) {
		std::cout << URED << "Error: Unable to use Materia, index is out of range" << RESET std::endl;
	} else if (!this->_slot[idx]) {
		std::cout << URED << "Error: Unable to use Materia, the _slot is empty" << RESET std::endl;
	} else {
		
		this->_slot[idx] = nullptr;
	}
}
