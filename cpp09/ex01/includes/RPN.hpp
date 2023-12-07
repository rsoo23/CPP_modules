/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:44:44 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/07 10:44:44 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"

#pragma once

class RPN {
    public:
        RPN();
        RPN( const RPN& other );
        RPN& operator=( const RPN& other );
		~RPN();

		void calculate( const std::string& expression );
		void checkExpressionFormat( const std::string& expression );
		void executeOperation( const char& op );

		class invalidExpressionFormat: public std::exception {
			public:
				const char* what() const throw();
		};

		class invalidExpressionOrder: public std::exception {
			public:
				const char* what() const throw();
		};

    private:
		std::stack<int> _stack;
		std::string _op;
};
