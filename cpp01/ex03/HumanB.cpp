/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:18:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 12:09:15 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

HumanB::HumanB( std::string name ): name(name) {}

~HumanB::HumanB( void ) {};

void HumanB::attack ( void ) {
	std::cout << YELLOW << name << RESET << " attacks with their " << BLUE << weapon_type << RESET << std::endl;
};
