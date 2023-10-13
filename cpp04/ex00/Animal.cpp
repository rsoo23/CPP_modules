/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:43:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/13 23:48:28 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal() {}

Animal::~Animal() {}

Animal::Animal( const Animal& other ) {
	*this = other;
}

Animal& operator=( const Animal& other ) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
