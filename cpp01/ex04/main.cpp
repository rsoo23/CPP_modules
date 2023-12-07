/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:03:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/29 10:26:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.h"

int main() {
	bool valid_input = false;
	std::string inputFilename;
	std::string outputFilename;
	std::string target_string;
	std::string replacement_string;
	MySed sed;

	while (valid_input == false) {
		std::cout << YELLOW << "Please enter your input file name: " << RESET;
		std::getline(std::cin, inputFilename);
		if (inputFilename.empty())
			continue;
		sed.setInputFilename(inputFilename);
		valid_input = sed.openInputFile();
	}

	valid_input = false;
	while (valid_input == false) {
		std::cout << YELLOW << "Target string: " << RESET;
		std::getline(std::cin, target_string);
		if (target_string.empty())
			continue;
		sed.setTargetString(target_string);
		valid_input = sed.findTargetString();
	}

	std::cout << YELLOW << "Replace with: " << RESET;
	std::getline(std::cin, replacement_string);
	sed.setReplacementString(replacement_string);

	outputFilename = sed.createOutputFile();
	sed.writeToOutputFile(outputFilename);
}

// Edge cases:
// string not found
// string with spaces
