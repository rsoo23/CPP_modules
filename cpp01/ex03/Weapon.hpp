/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:22:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 23:41:27 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unnecessary_violence.h"

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
	public:
		Weapon( void );
		Weapon( std::string type );
		~Weapon( void );

		const std::string& getType( void );
		void setType( std::string type );

	private:
		std::string type;
};

#endif
