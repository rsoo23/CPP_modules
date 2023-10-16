/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:50:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:50:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
// #include "Brain.hpp"

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

class Dog: public Animal {
	public:
		Dog();
        Dog( const Dog& other );
        Dog& operator=( const Dog& other );
		~Dog();

		virtual void makeSound() const;

		Brain* getBrain();
	
	private:
		Brain* brain;
};

#endif
