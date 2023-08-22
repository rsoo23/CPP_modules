/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:46:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 10:33:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {
    std::cout << "Zombie " << YELLOW << name << RESET << " is destroyed" << std::endl << std::endl;
}

void Zombie::announce( void ) {
    std::cout << YELLOW << name << ": " << RED << " BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::giveName ( std::string name ) {
	this->name = name;
}
