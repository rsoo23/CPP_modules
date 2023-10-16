/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:36:15 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 16:17:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	public:
		Animal();
		virtual ~Animal();

		// pure virtual function
		virtual void makeSound() const = 0;

		std::string getType() const;

	protected:
		std::string type;
};

#endif
