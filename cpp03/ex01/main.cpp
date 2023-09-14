/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:57:37 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/13 23:57:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {
    ClapTrap a;
    ClapTrap b("Peppa Pig");

    std::cout << std::endl;
    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;
    
    // a attacks b once
    a.attack(b.getName());
    b.takeDamage(a.getAD());

    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;
    
    // a attacks b until 0 EP
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.attack(b.getName());
    a.beRepaired(2);

    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;

    // b repairs
    b.beRepaired(3);

    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;

    // b self attacks    
    b.attack(b.getName());

    std::cout << std::endl;

    // b attacks a
    b.attack(a.getName());
    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;

    std::cout << std::endl;
}
