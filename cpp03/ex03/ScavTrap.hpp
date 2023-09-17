/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/15 18:12:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap& other );
        ScavTrap& operator=( const ScavTrap& other );
        ~ScavTrap();

        void attack( const std::string& target );
        void guardGate();
};

#endif

