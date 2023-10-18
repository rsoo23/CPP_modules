/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:37:45 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 15:42:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

// learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.

// createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.

void MateriaSource::deleteKnowledge( const MateriaSource& other ) {
    for (int i = 0; i < 4; i++) {
        if (other._knowledge[i] != nullptr) {
			delete this->_knowledge[i];
            this->_knowledge[i] = nullptr;
        }
    }
}

void MateriaSource::deepCopyKnowledge( const MateriaSource& other ) {
    for (int i = 0; i < 4; i++) {
        if (other._knowledge[i] != nullptr) {
            this->_knowledge[i] = other._knowledge[i]->clone();
        } else {
            this->_knowledge[i] = nullptr;
        }
    }
}

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_knowledge[i] = nullptr;
	}
	std::cout << GREEN << "MateriaSource Constructed" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_knowledge[i]) {
			delete this->_knowledge[i];
		}
	}
	std::cout << RED << "MateriaSource Destructed" << RESET << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
	deepCopyKnowledge(other);
	std::cout << GREEN << "MateriaSource Copied" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) {
	if (this != &other) {
		deleteKnowledge(other);
		deepCopyKnowledge(other);
	}
	std::cout << GREEN << "MateriaSource Assigned" << RESET << std::endl;
	return *this;
}

void MateriaSource::learnMateria( AMateria* m ) {
	for (int i = 0; i < 4; i++) {
		if (this->_knowledge[i] == nullptr) {
			this->_knowledge[i] = m;
			std::cout << UYEL << m->getType() << " is learnt and stored in position " << i << " in knowledge" << RESET << std::endl;
			return ;
		}
	}
	std::cout << URED << "Error: Unable to learn Materia, you have too much knowledge!!" << RESET << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria( std::string const& type ) {
	for (int i = 0; i < 4; i++) {
		if (this->_knowledge[i] && this->_knowledge[i]->getType() == type) {
			std::cout << BGRN << "Materia is created with type: " << this->_knowledge[i]->getType() << RESET << std::endl;
			return this->_knowledge[i]->clone();
		}
	}
	std::cout << URED << "Error: Unable to create Materia, your knowledge sucks!!" << RESET << std::endl;
	return nullptr;
}
