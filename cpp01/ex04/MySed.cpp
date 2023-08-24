/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:51:05 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 10:01:38 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.h"

MySed::MySed( void ) {
	this->inputFilename = "";
	this->target_string = "";
	this->replacement_string = "";
};

MySed::~MySed( void ) {};

void MySed::setInputFilename( std::string inputFilename ) {
	this->inputFilename = inputFilename;
}

void MySed::setOutputFilename( std::string outputFilename ) {
	this->outputFilename = outputFilename;
}

void MySed::setTargetString( std::string target_string ) {
	this->target_string = target_string;
}

void MySed::setReplacementString( std::string replacement_string ) {
	this->replacement_string = replacement_string;
}

bool MySed::openInputFile( void ) {
	std::ifstream inputFile(this->inputFilename);

	if (inputFile.is_open()) {
		std::cout << GREEN << "Input file opened" << RESET << std::endl;
		return (true);
	} else {
		std::cout << RED << "Input file does not exist" << RESET << std::endl;
	}
	return (false);
}

bool MySed::findTargetString( void ) {
	std::string buffer;
	std::ifstream inputFile(this->inputFilename);
	
	while (std::getline(inputFile, buffer)) {
		if (buffer.find(this->target_string) != std::string::npos) {
			std::cout << GREEN << "Word found!" << RESET << std::endl;
			return (true);
		}
	}
	std::cout << RED << "Word not found" << RESET << std::endl;
	return (false);
}

std::string MySed::createOutputFile( void ) {
	std::string outputFilename;
	int last_position;

	// filename: hi -> hi.replace
	// filename: hi.txt -> hi.replace
	last_position = this->inputFilename.find_last_of('.');
	if ((size_t)last_position == std::string::npos) {
		outputFilename.append(this->inputFilename);
	} else {
		outputFilename.append(this->inputFilename.substr(0, last_position));
	}
	outputFilename.append(".replace");

	std::ofstream outputFile(outputFilename);
	if (outputFile.is_open()) {
		std::cout << GREEN << "Output file (" << outputFilename << ") is created successfully" << RESET << std::endl;
	} else {
		std::cout << RED << "Failed to open output file" << RESET << std::endl;
	}
	return outputFilename;
}

void MySed::writeToOutputFile( std::string outputFilename ) {
	std::ifstream inputFile(this->inputFilename);
	std::ofstream outputFile(outputFilename);
	std::string buffer;

	size_t starting_pos;
	size_t target_str_pos;
	
	std::getline(inputFile, buffer);
	while (inputFile) {
		starting_pos = 0;
		target_str_pos = 0;

		while (starting_pos != std::string::npos) {
			
			target_str_pos = buffer.find(this->target_string, starting_pos);
			
			if (starting_pos == 0 && target_str_pos == std::string::npos) {
				outputFile << buffer << std::endl;
				std::getline(inputFile, buffer);
				break;
			}
			else if (starting_pos == target_str_pos) {
				outputFile << this->replacement_string;
				starting_pos += target_string.length();
			}
			else if (starting_pos < target_str_pos) {
				outputFile << buffer.substr(starting_pos, target_str_pos - starting_pos);
				starting_pos += target_str_pos - starting_pos;
			}
			if (target_str_pos == std::string::npos) {
				std::getline(inputFile, buffer);
				if (inputFile)
					outputFile << std::endl;
				break;
			}
		}
	}
	inputFile.close();
	outputFile.close();
}

// sentence this is very this
// long oh yeah baby this

// std::string::npos (size_t -1: max possible value of size_t)
// if find() returns this, that means the target you want to find is not present in the string
