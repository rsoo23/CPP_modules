/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:23:28 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 12:09:11 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

HumanA::HumanA( std::string name, Weapon weapon_type ): name(name), weapon_type(weapon_type) {};

HumanA::~HumanA( void ) {};

void HumanA::attack ( void ) {
	std::cout << YELLOW << name << RESET << " attacks with their " << BLUE << weapon_type << RESET << std::endl;
};
