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
	if (ac < 2) {
		std::cout << URED << "Argument error: please provide a positive integer sequence\nExample: ./PmergeMe 3 2 5 1" << RESET << std::endl;
		return 1;
	}
		
	try {
		PmergeMe p;

		p.assignInputToContainers(ac, av);
		p.checkDuplicates();
		p.checkSorted();

		p.startClock();
		p.fordJohnsonAlgorithm(p.getVec());
		p.stopClock();
		p.calculateDuration("vec");

		p.startClock();
		p.fordJohnsonAlgorithm(p.getLst());
		p.stopClock();
		p.calculateDuration("lst");

		p.printOutput( av );
	} catch (std::exception const& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}
