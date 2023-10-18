/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:18:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 16:13:46 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

class Cure: public AMateria {
	public:
		Cure();
		Cure( const Cure& other );
		Cure& operator=( const Cure& other );
		~Cure();

		AMateria* clone() const;
		void use( ICharacter& target );
};

#endif
