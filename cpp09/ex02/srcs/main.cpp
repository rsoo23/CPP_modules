/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:19:41 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/30 01:19:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

int main(int ac, char **av) {
		(void)av;
	if (ac > 1) {
		PmergeMe p;

		p.sort();
	} else {
		std::cout << URED << "Argument error: please provide a positive integer sequence\nExample: ./PmergeMe 3 2 5 1" << RESET << std::endl;
	}
}
