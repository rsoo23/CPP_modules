/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:46:52 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 10:34:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void ) {
	unsigned int number_of_zombies;
	bool valid_input = false;
	std::string name;

	while (valid_input != true)
	{
		std::cout << "How many " << GREEN << "zombies " << RESET << "do you want?: ";
		if (!(std::cin >> number_of_zombies)) {
            std::cout << RED << "Error: Only numeric inputs are allowed" << RESET << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
		if (number_of_zombies > 2147483648)
			std::cout << RED << "Error: Number is out of range" << RESET << std::endl;
		else
			valid_input = true;
	}

	std::cout << "What is your " << CYAN << "horde name" << RESET << "?: ";
	std::cin >> name;

	Zombie* zombieHordePointer = zombieHorde(number_of_zombies, name);

	for (unsigned int i = 0; i < number_of_zombies; i++) {
		std::cout << YELLOW << "Zombie " << i + 1 << ": " << RESET;
		zombieHordePointer[i].announce();
		std::cout << std::endl;
	}
	delete [] zombieHordePointer;
}
