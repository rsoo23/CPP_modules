/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:28 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/04 16:49:51 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parse_csv_file( const std::string& csv_file_path ) {
	std::ifstream csvFile( csv_file_path );
	std::string	line;

	if (!csvFile.is_open()) {
		std::cerr << URED "Error: data.csv unable to open / not found" RESET << std::endl;
		return ;
	}

	while (std::getline(csvFile, line)) {
		if (line == "date,exchange_rate")
			continue;
		// splits 2022-03-16,41133.08 into date = 2022-03-16 and exRate = 41133.08
		std::size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		std::string exRate = line.substr(commaPos + 1);
		
		// assign date and exRate into the unordered_map
		_btcDataMap[date] = std::stod(exRate);
	}
	// for debugging purposes: checks if the key-value pairs are correctly assigned
	// std::cout << "exRate: " << std::setprecision(9) << _btcDataMap["2009-01-02"] << std::endl;
}

void BitcoinExchange::parse_input_file( char* infile_name ) {
	std::string infile_str( infile_name );

	if (infile_str != "input.txt") {
		std::cerr << URED "Error: the input file name has to be input.txt" RESET << std::endl;
		return ;
	}

	std::ifstream inputFile( infile_str );
	std::string line;
	
	if (!inputFile.is_open()) {
		std::cerr << URED "Error: input.txt unable to open / not found" RESET << std::endl;
		return ;
	}
	while (std::getline(inputFile, line)) {
		if (line == "date | value")
			continue;
		// splits 2022-03-16 | 40 into date = 2022-03-16 and val = 40
		std::size_t commaPos = line.find('|');
		std::string date = line.substr(0, commaPos - 1);
		std::string val = line.substr(commaPos + 2);
		
	}
}

