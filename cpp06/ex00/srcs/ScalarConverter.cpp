/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:00:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/02 23:00:22 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter& other ) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

    // std::cout << UCYN "char: " << << RESET << std::endl;
    // std::cout << UYEL "int: " << << RESET << std::endl;
    // std::cout << UGRN "float: " << << RESET << std::endl;
    // std::cout << UPUR "double: " << << RESET << std::endl;

void handlePseudoLiterals( const std::string& input ) {
    std::cout << UCYN "char: impossible" RESET << std::endl;
    std::cout << UYEL "int: impossible" RESET << std::endl;
    if (input == "-inff" || input == "-inf") {
        std::cout << UGRN "float: -inff" RESET << std::endl;
        std::cout << UPUR "double: -inf" RESET << std::endl;
    } else if (input == "+inff" || input == "+inf") {
        std::cout << UGRN "float: +inff" RESET << std::endl;
        std::cout << UPUR "double: +inf" RESET << std::endl;
    } else if (input == "nanf" || input == "nan") {
        std::cout << UGRN "float: nanf" RESET << std::endl;
        std::cout << UPUR "double: nan" RESET << std::endl;
    }
}

/*
Possible inputs:
- int
- char
- float
- double

- -inff: imp, imp, -inff, -inf
- +inff: imp, imp, +inff, +inf
- nanf: imp, imp, nanf, nan

- -inf: imp, imp, -inff, -inf
- +inf: imp, imp, +inff, +inf
- nan: imp, imp, nanf, nan

Erroneous inputs:
- int, float, double with other symbols
- multiple char
- int, float, double out of range

*/
void ScalarConverter::convert( const std::string& input ) {
    // Pseudo literals
    std::string pseudoLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 6; i++) {
        if (input == pseudoLiterals[i]) {
            handlePseudoLiterals(input);
            return ;
        }
    }

    

    // std::cout << UCYN "char: " << atoi(input.c_str()) << RESET << std::endl;
}
