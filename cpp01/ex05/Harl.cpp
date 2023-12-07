/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:04:34 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 12:00:12 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl( void ) {};

Harl::~Harl( void ) {};

void Harl::complain( std::string level ) {
	void (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels_array[4] = {"debug", "info", "warning", "error"};
	
	for (int i = 0; i < 4; i++) {
		if (level == levels_array[i]) {
			(this->*funcPtr[i])();
			return;
		}
	}
};

void Harl::debug( void ) {
	std::cout << "DEBUG: " << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< RESET << std::endl;
};

void Harl::info( void ) {
	std::cout << "INFO: " << YELLOW << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< RESET << std::endl;
};

void Harl::warning( void ) {
	std::cout << "WARNING: " << CYAN << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< RESET << std::endl;
};

void Harl::error( void ) {
	std::cout << "ERROR: " << RED << "This is unacceptable! I want to speak to the manager now."
	<< RESET << std::endl;
};
