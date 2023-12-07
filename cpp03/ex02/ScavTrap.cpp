/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:43 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/15 18:12:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// constructors
ScavTrap::ScavTrap(): ClapTrap() {
    _name = "no name"; 
    _hitPoints = 100;
    _energyPoints = 50; 
    _attackDamage = 20;
    std::cout << GREEN << "ScavTrap constructor called: no name" << RESET << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap() {
    _name = name; 
    _hitPoints = 100;
    _energyPoints = 50; 
    _attackDamage = 20;
    std::cout << GREEN << "ScavTrap constructor called: " << name << RESET << std::endl;
}

// copy constructor
ScavTrap::ScavTrap( const ScavTrap& other ): ClapTrap() {
    std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
    *this = other;
}

// copy assignment operator
ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << GREEN << "ScavTrap copy assignment operator called" << RESET << std::endl;
    return *this;
}

// destructor
ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap destructor called" << RESET << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
    if (this->_name == target) {
        std::cout << RED << "Error: A ScavTrap can't attack itself!" RESET << std::endl;
        return ;
    } else if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 energy points left) :(" << RESET << std::endl;
        return ;
    } else if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 hit points left) :(" << RESET << std::endl;
        return ;
    }
    this->_energyPoints--;

    std::cout << "ScavTrap " << CYAN << this->_name << RESET \
    << " attacks " << PURPLE << target << RESET \
    << " causing " << RED << this->_attackDamage << RESET \
    << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << PURPLE << "ScavTrap is now in Gatekeeper mode" << RESET << std::endl;
}
