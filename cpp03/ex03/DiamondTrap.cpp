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

// FragTrap::_hitPoints = 100;
// FragTrap::_energyPoints = 100;
// FragTrap::_attackDamage = 30;

// ScavTrap::_hitPoints = 100;
// ScavTrap::_energyPoints = 50;
// ScavTrap::_attackDamage = 20;

// constructors
DiamondTrap::DiamondTrap(): ClapTrap() {
    _name = "no name";
    _hitPoints = FragTrap::_fragHitPoints;
    _energyPoints = ScavTrap::_scavEnergyPoints; 
    _attackDamage = FragTrap::_fragAttackDamage;
    std::cout << GREEN << "DiamondTrap constructor called: " << _name << RESET << std::endl;
}

// 2 problems:
// copy assignment operator doesn't work
// name + clap name doesn't
DiamondTrap::DiamondTrap( std::string name ): ClapTrap(), ScavTrap(), FragTrap(name + "_clap_name") {
    _name = name;
    _hitPoints = FragTrap::_fragHitPoints;
    _energyPoints = ScavTrap::_scavEnergyPoints;
    _attackDamage = FragTrap::_fragAttackDamage;
    std::cout << GREEN << "DiamondTrap constructor called: " << _name << RESET << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap( const DiamondTrap& other ): ClapTrap(), ScavTrap(), FragTrap(other._name) {
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

void DiamondTrap::whoAmI() {
    std::cout << PURPLE << "DiamondTrap name: " << this->_name << RESET << std::endl;
    std::cout << PURPLE << "ClapTrap name: " << ClapTrap::_name << RESET << std::endl;
}

// getter
std::string DiamondTrap::getName() {
	return this->_name;
}
