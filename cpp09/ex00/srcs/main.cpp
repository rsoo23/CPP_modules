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

#include "BitcoinExchange.h"

int main(int ac, char **av) {
	BitcoinExchange btc;

	if (ac == 2) {
		btc.parse_csv_file("data.csv");
		btc.parse_input_file(av[1]);
	} else {
		std::cerr << URED << "Error: only one argument allowed (./btc input.txt)" << RESET << std::endl;
	}
}
