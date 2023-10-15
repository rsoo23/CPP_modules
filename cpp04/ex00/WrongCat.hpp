/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:06:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 21:12:44 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

// WrongCat: does not have the virtual keyword for makeSound()

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
        WrongCat( const WrongCat& other );
        WrongCat& operator=( const WrongCat& other );
		~WrongCat();

		void makeSound() const;
};

#endif
