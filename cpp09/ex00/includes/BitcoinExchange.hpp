/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/04 13:16:40 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

#pragma once

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange( const BitcoinExchange& other );
        BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange();

		void parse_csv_file( const std::string& csv_file_path );
		void parse_input_file( char* infile_name );
		bool check_line_format( const std::string& line );
		bool check_valid_date( const std::string& date );
		bool check_valid_val( const std::string& val );

    private:
       std::map<std::string, float> _btcDataMap;
	   float _value;
	   std::string _date;
	   int _daysInMonth[12];
	   int _lineNum;
};
