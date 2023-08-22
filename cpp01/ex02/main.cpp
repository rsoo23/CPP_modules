/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:40:10 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 11:11:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define BLACK 	"\e[0;30m"
#define RED 	"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW 	"\e[0;33m"
#define BLUE 	"\e[0;34m"
#define PURPLE 	"\e[0;35m"
#define CYAN 	"\e[0;36m"
#define WHITE 	"\e[0;37m"
#define RESET 	"\e[0m"

int main ( void ) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << YELLOW << "Memory address of string variable: " << CYAN << &str << RESET << std::endl;
	std::cout << YELLOW << "Memory address held by strPTR:     " << BLUE << stringPTR << RESET << std::endl;
	std::cout << YELLOW << "Memory address held by strREF:     " << PURPLE << &stringREF << RESET << std::endl << std::endl;

	std::cout << YELLOW << "Value of string variable: " << CYAN << str << RESET << std::endl;
	std::cout << YELLOW << "Value held by strPTR:     " << BLUE << *stringPTR << RESET << std::endl;
	std::cout << YELLOW << "Value held by strREF:     " << PURPLE << stringREF << RESET << std::endl << std::endl;
}
