/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:47:00 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 10:30:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie* newZombieHorde = new Zombie[N];

	if (!newZombieHorde)
		std::cout << RED << "Memory allocation has failed" << RESET << std::endl;
	else {
		for (int i = 0; i < N; i++) {
			newZombieHorde[i].giveName(name);
		}
	}
	return (newZombieHorde);
}

