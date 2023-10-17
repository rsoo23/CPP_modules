/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:13:32 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/17 12:03:59 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character: public ICharacter {
	public:
		Character();
		Character( const Character& other );
		Character& operator=( const Character& other );
		~Character();

		std::string const& getName() const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, Character& target );

	private:
		std::string _name;
		AMateria *_slot[4];
		AMateria *_trash[100];
};

#endif

