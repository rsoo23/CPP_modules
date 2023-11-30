/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:00:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/30 11:53:26 by rsoo             ###   ########.fr       */
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

void handlePseudoLiterals( std::string input ) {
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

void handleCharacters( char c ) {
	std::cout << UCYN "char: '" << c << "'" << std::endl;
	std::cout << UYEL "int: " << static_cast<int>(c) << std::endl;
	std::cout << UGRN "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << UPUR "double: " << static_cast<double>(c) << ".0" RESET << std::endl;
}

/*
Accepts:
- 000.1f
- .34f

Rejects:
- 0.f
- 0.0ff
- 0-.0f
*/

bool correctFloatFormat( std::string input ) {
	int i = 0;

	if (input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '.')
		i++;
	if (!isdigit(input[i]))
		return false;
	while (isdigit(input[i]))
		i++;
	if (input[i] == 'f')
		i++;
	else
		return false;
	if (input[i] == '\0')
		return true;
	return false;
}

bool correctDoubleFormat( std::string input ) {
	int i = 0;

	if (input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '.')
		i++;
	else
		return false;
	if (input[i] == '\0')
		return false;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '\0')
		return true;
	return false;
}

bool correctIntFormat( std::string input ) {
	int i = 0;

	if (input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '\0')
		return true;
	return false;
}

void displayOutOfRange( void ) {
	std::cout << UCYN "char: non displayable" << std::endl;
	std::cout << UYEL "int: out of range" << std::endl;
	std::cout << UGRN "float: out of range" << std::endl;
	std::cout << UPUR "double: out of range" << std::endl;
}

void displayChar( double n ) {
	if (n > 32 && n < 127)
		std::cout << UCYN "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << UCYN "char: non displayable" << std::endl;
}

void displayInt( double n ) {
	if (n >= -2147483648 && n < 2147483648)
		std::cout << UYEL "int: " << static_cast<int>(n) << std::endl;
	else
		std::cout << UYEL "int: out of range" << std::endl;
}

void displayFloat( double n ) {
	if (n >= std::numeric_limits<float>::lowest() && n < std::numeric_limits<float>::max())
	{
		if (n < 1000000 && n > -1000000)
		{
			if (static_cast<float>(n) == static_cast<float>(std::floor(n)))
				std::cout << UGRN "float: " << static_cast<float>(n) << ".0f" << std::endl;
			else
				std::cout << UGRN "float: " << static_cast<float>(n) << "f" << std::endl;
		}
		else if (!(n < 1000000 && n > -1000000))
			std::cout << UGRN "float: " << static_cast<float>(n) << "f" << std::endl;
		else
			std::cout << UGRN "float: " << static_cast<float>(n) << std::endl;
	}
	else
		std::cout << UGRN "float: out of range" << std::endl;
}

void displayDouble( double n ) {
	// the last condition checks if a double has a fractional part (e.g. 42.2) or not (e.g. 42.0)
	if (n < 1000000 && n > -1000000 && static_cast<double>(n) == static_cast<double>(std::floor(n))) {
		std::cout << UPUR "double: " << n << ".0" << std::endl;
		return ;
	}
	std::cout << UPUR "double: " << n << std::endl;
}

void handleNumbers( std::string input ) {
	try {
		double n = std::stod(input);

		displayChar(n);
		displayInt(n);
		displayFloat(n);
		displayDouble(n);
	} catch (const std::exception& e) {
		displayOutOfRange();
	}
}

void ScalarConverter::convert( std::string input ) {
    std::string pseudoLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 6; i++) {
        if (input == pseudoLiterals[i]) {
            handlePseudoLiterals(input);
            return ;
        }
    }
	if (strlen(input.c_str()) == 1 && !isdigit((int)((input.c_str())[0]))) {
		handleCharacters((input.c_str())[0]);
	} else if (correctFloatFormat(input) || correctDoubleFormat(input) || correctIntFormat(input)) {
		handleNumbers(input);
	} else {
		std::cout << RED "Error: Input Format" RESET << std::endl;
	}
}
