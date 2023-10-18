/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 14:20:22 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP


class MateriaSource: public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );
		~MateriaSource();

		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const& type );

		void deleteKnowledge( const MateriaSource& other );
		void deepCopyKnowledge( const MateriaSource& other );
	
	private:
		AMateria* _knowledge[4];
};
 
#endif
