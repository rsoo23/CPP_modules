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
    std::cout << std::endl;
    ScavTrap b("Jackson Michael");
    std::cout << std::endl;
    FragTrap c("Lord Farquaad");
    std::cout << std::endl;
    FragTrap d;
    std::cout << std::endl;
    FragTrap e( c );
    std::cout << std::endl;
    d = c;

    std::cout << std::endl;
    std::cout << c.getName() << ": " << RESET << "HP=" << c.getHP() << ", EP=" << c.getEP() << ", AD=" << c.getAD() << std::endl;
    std::cout << d.getName() << ": " << RESET << "HP=" << d.getHP() << ", EP=" << d.getEP() << ", AD=" << d.getAD() << std::endl;
    std::cout << e.getName() << ": " << RESET << "HP=" << e.getHP() << ", EP=" << e.getEP() << ", AD=" << e.getAD() << std::endl << std::endl;
    
    // c, d, e activates highFiveGuys
    c.highFiveGuys();
    d.highFiveGuys();
    e.highFiveGuys();
    std::cout << std::endl;

    // c attacks a
    c.attack(a.getName());
    a.takeDamage(c.getAD());
    std::cout << std::endl;

    std::cout << a.getName() << ": " << RESET << "HP=" << a.getHP() << ", EP=" << a.getEP() << ", AD=" << a.getAD() << std::endl;
    std::cout << c.getName() << ": " << RESET << "HP=" << c.getHP() << ", EP=" << c.getEP() << ", AD=" << c.getAD() << std::endl << std::endl;
    
    // c is repaired
    c.beRepaired(2);
    std::cout << c.getName() << ": " << RESET << "HP=" << c.getHP() << ", EP=" << c.getEP() << ", AD=" << c.getAD() << std::endl << std::endl;

    // c self attacks    
    c.attack(c.getName());
    std::cout << std::endl;
}
