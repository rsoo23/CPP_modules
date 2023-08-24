/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:04:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 10:20:02 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

#ifndef HARL_H
#define HARL_H

class Harl {
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
