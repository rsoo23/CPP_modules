/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:32 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 17:13:40 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define TRASH_SIZE 100

class Character: public ICharacter {
	public:
		Character();
		Character( std::string name );
		Character( const Character& other );
		Character& operator=( const Character& other );
		~Character();

		std::string const& getName() const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );

		void setSlotAndTrash();
		void deleteSlotAndTrash( const Character& other );
		void deepCopySlotAndTrash( const Character& other );

		AMateria** getSlot();
		AMateria** getTrash();

	private:
		std::string _name;
		AMateria* _slot[4];
		AMateria* _trash[TRASH_SIZE];
};

#endif

