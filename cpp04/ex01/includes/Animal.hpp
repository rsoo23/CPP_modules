/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:36:15 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 20:25:09 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	public:
		Animal();
		Animal( std::string type );
        Animal( const Animal& other );
        Animal& operator=( const Animal& other );
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;

	protected:
		std::string type;
};

#endif
