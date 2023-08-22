/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:55 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 23:30:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

#pragma once
#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

class HumanB {
	public:
		HumanB( std::string name );
		~HumanB();
		void attack( void );
		void setWeapon ( Weapon weapon_type );

	private:
		std::string name;
		Weapon weapon_type;
};


#endif
