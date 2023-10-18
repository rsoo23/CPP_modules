/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:09:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 16:13:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

class Ice: public AMateria {
	public:
		Ice();
		Ice( const Ice& other );
		Ice& operator=( const Ice& other );
		~Ice();

		AMateria* clone() const;
		void use( ICharacter& target );
};

#endif
