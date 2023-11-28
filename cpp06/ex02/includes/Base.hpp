/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:04:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 15:18:18 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.h"

#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		virtual ~Base();
};

Base* generate( void );
void identify( Base* p );
void identify( Base& p );

#endif
