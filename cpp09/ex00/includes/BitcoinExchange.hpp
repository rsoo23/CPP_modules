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

    private:
       std::unordered_map<std::string, double> _btcDataMap;
};
