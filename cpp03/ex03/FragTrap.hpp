/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:21:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/17 21:21:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap( std::string name );
        FragTrap( const FragTrap& other );
        FragTrap& operator=( const FragTrap& other );
        ~FragTrap();

        void attack( const std::string& target );
        void highFiveGuys();
	
	protected:
        static unsigned int _fragHitPoints;
        static unsigned int _fragEnergyPoints;
        static unsigned int _fragAttackDamage;
};

#endif
