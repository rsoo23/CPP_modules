/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:28 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/06 17:41:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() {
	_daysInMonth[0] = 31; 
	_daysInMonth[1] = 28; 
	_daysInMonth[2] = 31; 
	_daysInMonth[3] = 30; 
	_daysInMonth[4] = 31; 
	_daysInMonth[5] = 30; 
	_daysInMonth[6] = 31; 
	_daysInMonth[7] = 31; 
	_daysInMonth[8] = 30; 
	_daysInMonth[9] = 31; 
	_daysInMonth[10] = 30; 
	_daysInMonth[11] = 31;
	_lineNum = 2;
}

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
	// std::cout << "exRate: " << std::setprecision(9) << _btcDataMap["2011-01-03"] << std::endl;
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
		if (!check_line_format(line)) {
			std::cerr << URED << _lineNum++ << ": bad input => " << line << RESET << std::endl;
			continue;
		}
		// finds index of '|'
		std::size_t barPos = line.find('|');
		// splits 2022-03-16 | 40 into date = 2022-03-16 and val = 40
		std::string date = line.substr(0, barPos - 1);
		std::string val = line.substr(barPos + 2);
		// if both format checks pass then output calculation
		if (check_valid_date(date) && check_valid_val(val)) {
			std::map<std::string, float>::iterator it = _btcDataMap.lower_bound(date);
			float res = it->second * _value;

			std::cout << std::setprecision(3) << GREEN << _lineNum++ << ": " << date << " => " << it->second << " * " << val << " = " << res << std::endl;
		}
	}
}

// sets very strict constraints on the format
bool BitcoinExchange::check_line_format( const std::string& line ) {
	int i = 0;

	while (isdigit(line[i]))
		i++;
	for (int j = 0; j < 2; j++) {
		if (line[i] == '-')
			i++;
		else
			return false;
		while (isdigit(line[i]))
			i++;
	}

	if (line[i] == ' ')
		i++;
	else
		return false;
	if (line[i] == '|')
		i++;
	else
		return false;
	if (line[i] == ' ')
		i++;
	else
		return false;

	if (line[i] == '-' || isdigit(line[i]))
		i++;
	else
		return false;
	if (line[i] == '.' || isdigit(line[i]))
		i++;
	if (line[i] == '.' || isdigit(line[i]))
		i++;
	while (isdigit(line[i]))
		i++;
	if (line[i])
		return false;
	return true;
}

// checks if the year, month and day is all within correct ranges
bool BitcoinExchange::check_valid_date( const std::string& date ) {
	std::size_t firstDashPos = date.find('-');
	std::size_t lastDashPos = date.rfind('-');
	
	// splits 2011-01-03 into 2011, 01, 03
	int year = std::stoi(date.substr(0, firstDashPos));
	int month = std::stoi(date.substr(firstDashPos + 1, lastDashPos - firstDashPos - 1));
	int day = std::stoi(date.substr(lastDashPos + 1));
	
	if (year < 2009 || year > 2022) {
		std::cerr << URED << _lineNum++ << ": year (" << year << ") is out of range [2009, 2022]" << RESET << std::endl;
		return false;
	} else if (month < 1 || month > 12) {
		std::cerr << URED << _lineNum++ << ": month (" << month << ") is out of range [1, 12]" << RESET << std::endl;
		return false;
	} else if (day < 1 || day > _daysInMonth[month - 1]) {
		if (month == 2 && year % 4 == 0 && day == 29)
			return true;
		std::cerr << URED << _lineNum++ << ": day (" << day << ") is out of range [1, " << _daysInMonth[month - 1] << "]" << RESET << std::endl;
		return false;
	}
	return true;
}

// checks if the value is within range
bool BitcoinExchange::check_valid_val( const std::string& val ) {
	_value = std::stof(val);

	if (_value < 0 || _value > 1000) {
		std::cerr << URED << _lineNum++ << ": value (" << _value << ") is out of range [0, 1000]" << RESET << std::endl;
		return false;
	}
	return true;
}
