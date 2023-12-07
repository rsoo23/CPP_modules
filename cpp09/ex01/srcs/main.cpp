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

#include "RPN.h"

int main(int ac, char **av) {
	if (ac == 2) {
		RPN rpn;

		rpn.calculate(av[1]);
	} else {
		std::cout << URED << "Error: only one argument is allowed (./RPN \"inverted Polish mathematical expression\")" << RESET << std::endl;
	}
}
