/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:38:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/21 23:38:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << YELLOW << "[stack] " << RESET << "Please enter " << GREEN << "zombie " << RESET << "name: ";
    std::cin >> name;

	Zombie stackZombie = Zombie(name);
	stackZombie.announce();

    std::cout << YELLOW << "[heap] " << RESET << "Please enter " << GREEN << "zombie " << RESET << "name: ";
    std::cin >> name;

	Zombie* zombiePointer = newZombie(name);
	zombiePointer->announce();
	delete zombiePointer;

    std::cout << YELLOW << "[chump] " << RESET << "Please enter " << GREEN << "zombie " << RESET << "name: ";
    std::cin >> name;

	randomChump(name);
}
