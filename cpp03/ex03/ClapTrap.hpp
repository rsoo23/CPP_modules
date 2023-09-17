/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:05:08 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/13 23:05:08 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap& other );
        ClapTrap& operator=( const ClapTrap& other );
        ~ClapTrap();

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

        std::string getName() const;
        unsigned int getHP() const;
        unsigned int getEP() const;
        unsigned int getAD() const;

    protected:
        std::string  _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif
