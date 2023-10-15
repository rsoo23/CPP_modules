/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:51:39 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 20:55:34 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

class Cat: public Animal {
	public:
		Cat();
        Cat( const Cat& other );
        Cat& operator=( const Cat& other );
		~Cat();

		virtual void makeSound() const;
};

#endif
