/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:42:49 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/07 23:42:49 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

#pragma once

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe();

		// class invalidExpressionFormat: public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };

    private:

};
