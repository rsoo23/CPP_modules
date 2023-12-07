/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:22:10 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/23 09:15:09 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {};

Weapon::Weapon( std::string type ): type(type) {};

Weapon::~Weapon( void ) {};

const std::string& Weapon::getType( void ) {
	return type;
};

void Weapon::setType( std::string type ) {
	this->type = type;
};
