/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:22:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 12:07:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "unnecessary_violence.h"

class Weapon {
	public:
		Weapon( std::string type );
		~Weapon( void );

		std::string& getType( void ) const;
		void setType( std::string type );

	private:
		std::string type;
};

#endif
