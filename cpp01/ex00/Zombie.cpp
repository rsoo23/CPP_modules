/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:42:54 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/21 23:42:54 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->name = name;
}

Zombie::~Zombie( void ) {
    std::cout << "Zombie " << YELLOW << name << RESET << " is destroyed" << std::endl << std::endl;
}

void Zombie::announce( void ) {
    std::cout << YELLOW << name << ":" << RED << " BraiiiiiiinnnzzzZ..." << RESET << std::endl << std::endl;
}
