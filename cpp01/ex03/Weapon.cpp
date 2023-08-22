/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:22:10 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 12:09:17 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

Weapon::Weapon( std::string type ): type(type) {};

~Weapon::Weapon( void ) {};

std::string& getType( void ) const {
	return (type);
};

void setType( std::string type ) {
	this->type = type;
};
