/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:57:15 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

// WrongAnimal: does not have the virtual keyword for its destructor and makeSound()
// Result: only calls the destructor and makeSound() of the base class

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal( std::string type );
        WrongAnimal( const WrongAnimal& other );
        WrongAnimal& operator=( const WrongAnimal& other );
		virtual ~WrongAnimal();

		void makeSound() const;

		std::string getType() const;

	protected:
		std::string type;
};

#endif
