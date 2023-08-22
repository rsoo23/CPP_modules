/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:18:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 23:56:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

HumanB::HumanB( std::string name ): name(name) {};

HumanB::~HumanB( void ) {};

void HumanB::attack ( void ) {
	std::cout << YELLOW << name << RESET << " attacks with their " << PURPLE << weapon_type.getType() << RESET << std::endl;
};

void HumanB::setWeapon( Weapon weapon_type ) {
	this->weapon_type = weapon_type;
}
