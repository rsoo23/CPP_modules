/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:43:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/08 00:08:15 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
	(void)other;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}
