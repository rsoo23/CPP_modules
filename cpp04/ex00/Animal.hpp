/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:36:15 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/13 23:50:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	public:
		Animal();
        Animal( const Animal& other );
        Animal& operator=( const Animal& other );
		~Animal();

	protected:
		std::string type;
};

#endif
