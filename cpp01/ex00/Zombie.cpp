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

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {
    std::cout << "Zombie" << name << "is destroyed" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
