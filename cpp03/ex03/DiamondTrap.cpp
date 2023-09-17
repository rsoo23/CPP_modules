/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:55:59 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/17 21:55:59 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// constructors
DiamondTrap::DiamondTrap(): ClapTrap() {
    _name = "no name"; 
    _hitPoints = 100;
    _energyPoints = 50; 
    _attackDamage = 20;
    std::cout << GREEN << "DiamondTrap constructor called: no name" << RESET << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap() {
    _name = name; 
    _hitPoints = 100;
    _energyPoints = 50; 
    _attackDamage = 20;
    std::cout << GREEN << "DiamondTrap constructor called: " << name << RESET << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap( const DiamondTrap& other ): ClapTrap() {
    std::cout << GREEN << "DiamondTrap copy constructor called" << RESET << std::endl;
    *this = other;
}

// copy assignment operator
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other ) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << GREEN << "DiamondTrap copy assignment operator called" << RESET << std::endl;
    return *this;
}

// destructor
DiamondTrap::~DiamondTrap() {
    std::cout << RED << "DiamondTrap destructor called" << RESET << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
    if (this->_name == target) {
        std::cout << RED << "Error: A DiamondTrap can't attack itself!" RESET << std::endl;
        return ;
    } else if (this->_energyPoints == 0) {
        std::cout << "DiamondTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 energy points left) :(" << RESET << std::endl;
        return ;
    } else if (this->_hitPoints == 0) {
        std::cout << "DiamondTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 hit points left) :(" << RESET << std::endl;
        return ;
    }
    this->_energyPoints--;

    std::cout << "DiamondTrap " << CYAN << this->_name << RESET \
    << " attacks " << PURPLE << target << RESET \
    << " causing " << RED << this->_attackDamage << RESET \
    << " points of damage!" << std::endl;
}

void DiamondTrap::guardGate() {
    std::cout << PURPLE << "DiamondTrap is now in Gatekeeper mode" << RESET << std::endl;
}
