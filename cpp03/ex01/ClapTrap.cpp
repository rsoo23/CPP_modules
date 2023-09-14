/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:12:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/13 23:12:40 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// constructors
ClapTrap::ClapTrap(): _name("no name"),  _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "Constructor called: no name" << RESET << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name),  _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "Constructor called: " << name << RESET << std::endl;
}

// copy constructor
ClapTrap::ClapTrap( const ClapTrap& other ) {
    *this = other;
}

// copy assignment operator
ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// destructor
ClapTrap::~ClapTrap() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

// getters
std::string ClapTrap::getName() const {
    return this->_name;
}

unsigned int ClapTrap::getHP() const {
    return this->_hitPoints;
}

unsigned int ClapTrap::getEP() const {
    return this->_energyPoints;
}

unsigned int ClapTrap::getAD() const {
    return this->_attackDamage;
}

void ClapTrap::attack( const std::string& target ) {
    if (this->_name == target) {
        std::cout << RED << "Error: A ClapTrap can't attack itself!" RESET << std::endl;
        return ;
    } else if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 energy points left) :(" << RESET << std::endl;
        return ;
    } else if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 hit points left) :(" << RESET << std::endl;
        return ;
    }
    this->_energyPoints--;

    std::cout << "ClapTrap " << CYAN << this->_name << RESET \
    << " attacks " << PURPLE << target << RESET \
    << " causing " << RED << this->_attackDamage << RESET \
    << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << CYAN << this->_name << RESET \
        << " cannot take damage " << RED << "(0 hit points left) :(" << RESET << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
}


void ClapTrap::beRepaired( unsigned int amount ) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << CYAN << this->_name << RESET \
        << " cannot repair " << RED << "(0 energy points left) :(" << RESET << std::endl;
        return ;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << CYAN << this->_name << RESET \
    << " repairs " << GREEN << amount << " hit points! :)" << RESET << std::endl;
    this->_hitPoints += amount;
}


