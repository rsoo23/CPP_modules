/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 17:13:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

void Character::setSlotAndTrash() {
	for (int i = 0; i < 4; i++) {
		this->_slot[i] = nullptr;
	}
	for (int i = 0; i < TRASH_SIZE; i++) {
		this->_trash[i] = nullptr;
	}
}

void Character::deleteSlotAndTrash( const Character& other ) {
    for (int i = 0; i < 4; i++) {
        if (other._slot[i] != nullptr) {
			delete this->_slot[i];
			this->_slot[i] = nullptr;
        }
    }
    for (int i = 0; i < TRASH_SIZE; i++) {
        if (other._trash[i] != nullptr) {
			delete this->_trash[i];
			this->_trash[i] = nullptr;
        }
    }
}

void Character::deepCopySlotAndTrash( const Character& other ) {
    for (int i = 0; i < 4; i++) {
        if (other._slot[i] != nullptr) {
            this->_slot[i] = other._slot[i]->clone();
        } else {
            this->_slot[i] = nullptr;
        }
    }

    for (int i = 0; i < TRASH_SIZE; i++) {
        if (other._trash[i] != nullptr) {
            this->_trash[i] = other._trash[i]->clone();
        } else {
            this->_trash[i] = nullptr;
        }
	}
}

// default constructor
Character::Character(): _name("no name") {
	setSlotAndTrash();
	std::cout << GREEN << "Character Constructed" << RESET << std::endl;
}

// parameterized constructor
Character::Character( std::string name ): _name(name) {
	setSlotAndTrash();
	std::cout << GREEN << "Character Constructed with name: " << name << RESET << std::endl;
}

// destructor
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i] != nullptr) {
			delete this->_slot[i];
		}
	}

    for (int i = 0; i < TRASH_SIZE; i++) {
        if (this->_trash[i] != nullptr) {
			delete this->_trash[i];
		}
	}

	std::cout << RED << "Character Destructed" << RESET << std::endl;
}

// copy constructor
Character::Character( const Character& other ) {
	this->_name = other._name;
	deepCopySlotAndTrash(other);
	std::cout << GREEN << "Character Copied" << RESET << std::endl;
}

// copy assignment operator
Character& Character::operator=( const Character& other ) {
	if (this != &other) {	
		this->_name = other._name;
		deleteSlotAndTrash(other);
		deepCopySlotAndTrash(other);
	}
	std::cout << GREEN << "Character Assigned" << RESET << std::endl;
	return *this;
}

std::string const& Character::getName() const {
	return this->_name;
}

void Character::equip( AMateria* m ) {
	if (m == nullptr) {
		std::cout << URED << "Error: Unable to equip Materia, Materia is non-existent" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_slot[i] == nullptr) {
			this->_slot[i] = m;
			std::cout << UYEL << m->getType() << " is equipped to slot " << i << RESET << std::endl;
			return ;
		}
	}
	std::cout << URED << "Error: Unable to equip Materia, inventory is full" << RESET << std::endl;
	delete m;
}

/*
Cases:
- out of range
- _slot is empty
- _slot is equipped
*/
void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3) {
		std::cout << URED << "Error: Unable to unequip Materia, index is out of range" << RESET << std::endl;
	} else if (this->_slot[idx] == nullptr) {
		std::cout << URED << "Error: Unable to unequip Materia, the slot is already empty" << RESET << std::endl;
	} else {
		for (int i = 0; i < TRASH_SIZE; i++) {
			if (!this->_trash[i]) {
				std::cout << UYEL << this->_slot[idx]->getType() << " is unequipped from slot " << idx << RESET << std::endl;
				this->_trash[i] = this->_slot[idx];
				this->_slot[idx] = nullptr;
				return ;
			}	
		}
		std::cout << URED << "Error: Your trash is full" << RESET << std::endl;
	}
}

void Character::use( int idx, ICharacter& target ) {
	if (idx < 0 || idx > 3) {
		std::cout << URED << "Error: Unable to use Materia, index is out of range" << RESET << std::endl;
	} else if (!this->_slot[idx]) {
		std::cout << URED << "Error: Unable to use Materia, the slot is empty" << RESET << std::endl;
	} else {
		this->_slot[idx]->use(target);
	}
}

AMateria** Character::getSlot() {
	return this->_slot;
}

AMateria** Character::getTrash() {
	return this->_trash;
}

