/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:36:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 16:47:33 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria {
	public:
		AMateria();
		AMateria( std::string& const type );
		virtual ~AMateria();
		
		std::string const & getType() const; // Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string type;
};

#endif
