/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:21:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/17 21:21:09 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// constructors
FragTrap::FragTrap(): ClapTrap() {
    _name = "no name"; 
    _hitPoints = 100;
    _energyPoints = 100; 
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap constructor called: no name" << RESET << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap() {
    _name = name; 
    _hitPoints = 100;
    _energyPoints = 100; 
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap constructor called: " << name << RESET << std::endl;
}

// copy constructor
FragTrap::FragTrap( const FragTrap& other ): ClapTrap() {
    std::cout << GREEN << "FragTrap copy constructor called" << RESET << std::endl;
    *this = other;
}

// copy assignment operator
FragTrap& FragTrap::operator=( const FragTrap& other ) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << GREEN << "FragTrap copy assignment operator called" << RESET << std::endl;
    return *this;
}

// destructor
FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
}

void FragTrap::attack( const std::string& target ) {
    if (this->_name == target) {
        std::cout << RED << "Error: A FragTrap can't attack itself!" RESET << std::endl;
        return ;
    } else if (this->_energyPoints == 0) {
        std::cout << "FragTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 energy points left) :(" << RESET << std::endl;
        return ;
    } else if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << CYAN << this->_name << RESET \
        << " cannot attack " << RED << "(0 hit points left) :(" << RESET << std::endl;
        return ;
    }
    this->_energyPoints--;

    std::cout << "FragTrap " << CYAN << this->_name << RESET \
    << " attacks " << PURPLE << target << RESET \
    << " causing " << RED << this->_attackDamage << RESET \
    << " points of damage!" << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << BLUE << "Can I get a high five guys??" << RESET << std::endl;
}
