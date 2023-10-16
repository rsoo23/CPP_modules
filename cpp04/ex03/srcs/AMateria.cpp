/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:43:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 16:48:33 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria() {
	std::cout << GREEN << "AMateria Constructed" << RESET << std::endl;
}

AMateria::AMateria( std::string& const type ) {
	std::cout << GREEN << "AMateria Constructed with type: "<< type << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << RED << "AMateria Destructed" << RESET << std::endl;
}


