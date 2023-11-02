/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:15:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/02 13:38:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Intern::Intern() {
	std::cout << GREEN "Intern constructed" RESET << std::endl;
}

Intern::Intern( Intern const& other ) {
	(void)other;
}

Intern& Intern::operator=( Intern const& other ) {
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << RED "Intern destructed" RESET << std::endl;
}

AForm* Intern::makeForm( std::string formName, std::string target ) {
	std::string formNames[3] = {SHRUB_FORM_NAME, ROBO_FORM_NAME, PRES_FORM_NAME};
	AForm* (Intern::*formPointers[3])(std::string) = {&Intern::ShrubberyCreate, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << UYEL "Intern creates " << formName << RESET << std::endl;
			return (this->*formPointers[i])(target);
		}
	}
	std::cout << BRED "Warning: Form " << formName << " doesn't exist" RESET << std::endl;
	return nullptr;
}

AForm* Intern::ShrubberyCreate( std::string target ) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::RobotomyRequest( std::string target ) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::PresidentialPardon( std::string target ) {
	return (new PresidentialPardonForm(target));
}
