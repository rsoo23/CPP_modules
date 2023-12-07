/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:18:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/23 09:22:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

HumanB::HumanB( std::string name ) {
	this->name = name;
	this->weapon_type = NULL;
};

// everytime constructor is called you need to initialize all variables
// since Weapon is not passed into the constructor, we need it to default to something else (so list initialization does not work)
// so we have to set weapon_type as a Weapon*, so that we can set it to NULL in the constructor

HumanB::~HumanB( void ) {};

void HumanB::attack ( void ) {
	std::cout << YELLOW << name << RESET << " attacks with their " << PURPLE << weapon_type->getType() << RESET << std::endl;
};

void HumanB::setWeapon( Weapon& weapon_type ) {
	this->weapon_type = &weapon_type;
}
