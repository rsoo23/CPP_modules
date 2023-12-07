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
    ClapTrap a("Peppa Pig");
    ScavTrap b;
    ScavTrap c("Jackson Michael");
    ScavTrap d( c );
    ScavTrap e;
    d = c;

    std::cout << std::endl;
    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl;
    std::cout << c.getName() << ": " << RESET << "HP=" << c.getHP() << ", EP=" << c.getEP() << ", AD=" << c.getAD() << std::endl;
    std::cout << d.getName() << ": " << RESET << "HP=" << d.getHP() << ", EP=" << d.getEP() << ", AD=" << d.getAD() << std::endl;
    std::cout << e.getName() << ": " << RESET << "HP=" << e.getHP() << ", EP=" << e.getEP() << ", AD=" << e.getAD() << std::endl << std::endl;
    
    // b activates guardGate
    b.guardGate();
    std::cout << std::endl;

    // b attacks a
    b.attack(a.getName());
    a.takeDamage(b.getAD());
    std::cout << std::endl;

    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;
    
    // b is repaired
    b.beRepaired(2);
    std::cout << b.getName() << ": " << RESET << "HP=" << b.getHP() << ", EP=" << b.getEP() << ", AD=" << b.getAD() << std::endl << std::endl;

    // b self attacks    
    b.attack(b.getName());
    std::cout << std::endl;
}
