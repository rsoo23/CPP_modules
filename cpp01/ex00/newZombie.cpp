/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:42:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/21 23:42:51 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie* newZombie = new Zombie(name);

	if (!newZombie)
		std::cout << "Memory allocation has failed" << std::endl;

	return (newZombie);
}
