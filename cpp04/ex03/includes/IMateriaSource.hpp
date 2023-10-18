/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:43:05 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 16:29:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

#pragma once
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria( AMateria* ) = 0;
		virtual AMateria* createMateria( std::string const& type ) = 0;
};

#endif

