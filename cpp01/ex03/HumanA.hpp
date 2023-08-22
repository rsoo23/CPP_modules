/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 12:07:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "unnecessary_violence.h"

class HumanA {
	public:
		HumanA( std::string name, Weapon weapon_type );
		~HumanA( void );
		void attack( void );

	private:
		std::string name;
		Weapon weapon_type;
};

#endif

// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course, without the
// angle brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.
