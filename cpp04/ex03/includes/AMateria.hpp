/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:36:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 13:41:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria( const std::string& type );
		AMateria( const AMateria& other );
		AMateria& operator=( const AMateria& other );
		virtual ~AMateria();

		std::string const& getType() const; // Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );

	protected:
		std::string type;
};

#endif
