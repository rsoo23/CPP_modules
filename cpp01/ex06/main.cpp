/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:37:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 13:48:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int ac, char **av) {
	Harl harl;
	int levels_index = -1;
	std::string levels_array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};


	if (ac == 2) {
		for (int i = 0; i < 4; i++) {
			if ((std::string)av[1] == levels_array[i]) {
				levels_index = i;
				break;
			}
		}
		switch (levels_index) {
			case 0:
				harl.complain(levels_array[levels_index++]);
			case 1:
				harl.complain(levels_array[levels_index++]);
			case 2:
				harl.complain(levels_array[levels_index++]);
			case 3:
				harl.complain(levels_array[levels_index]);
				break;
			default:
				std::cout << YELLOW << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
		}
		
	} else {
		std::cout << RED << "Error: Wrong number of arguments" << RESET << std::endl;
	}
}
