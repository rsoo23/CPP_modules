/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:55:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/17 21:55:53 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

// inheritance order: inherits the last one (FragTrap)
class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap();
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap& other );
        DiamondTrap& operator=( const DiamondTrap& other );
        ~DiamondTrap();

		using ScavTrap::attack;

		void whoAmI();
		std::string getName();

	private:
		std::string _name;
};

#endif
