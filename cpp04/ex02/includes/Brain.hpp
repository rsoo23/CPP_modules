/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:39:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 14:39:47 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain {
	public:
		Brain();
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		~Brain();

	private:
		std::string ideas[100];
};

#endif
