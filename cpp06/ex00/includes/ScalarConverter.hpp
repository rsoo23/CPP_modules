/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:00:17 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/29 10:17:18 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {
    public:
        static void convert( std::string input );

    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other );
        ~ScalarConverter();
};

#endif
