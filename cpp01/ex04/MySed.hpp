/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:51:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/23 15:54:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_is_for_losers.h"

#pragma once
#ifndef MySed_HPP
#define MySed_HPP

class MySed {
	public:
		MySed( void );
		~MySed( void );

		bool openInputFile( void );
		bool findTargetString( void );
		std::string createOutputFile( void );
		void writeToOutputFile( std::string outputFilename );
	
		void setInputFilename( std::string inputFilename );
		void setOutputFilename( std::string outputFilename );
		void setTargetString( std::string target_string );
		void setReplacementString( std::string replacement_string );
		
	private:
		std::string inputFilename;
		std::string outputFilename;
		std::string target_string;
		std::string replacement_string;
};

#endif
