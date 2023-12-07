/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:37:39 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 11:59:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

class Harl {
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level );
		void complainLoop( int starting_index );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
