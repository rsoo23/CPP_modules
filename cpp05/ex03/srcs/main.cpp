/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:37:34 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 21:50:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void newline() {
	std::cout << std::endl;
}

void separator() {
	std::cout << "_________________________________________________________________________________" << std::endl;
}

void shrubbery_valid_tests() {
	try {
		ShrubberyCreationForm randoForm;
		newline();
		ShrubberyCreationForm bushForm("Garden");
		newline();
		Bureaucrat alpha("Alpha", 1);
		newline();
		
		randoForm.beSigned(alpha);
		alpha.signForm(bushForm);
		newline();

		// execute + executeForm with valid bureaucrat
		randoForm.execute(alpha);
		alpha.executeForm(bushForm);
		newline();

	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void unsigned_shrubbery_tests() {
	ShrubberyCreationForm bushForm("Garden");
	newline();
	Bureaucrat alpha("Alpha", 150);
	newline();
	// executeForm with unsigned form
	try {
		alpha.executeForm(bushForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	newline();
	// execute with unsigned form
	try {
		bushForm.execute(alpha);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void weak_bureaucrat_shrubbery_tests() {
	ShrubberyCreationForm bushForm("Garden");
	newline();
	Bureaucrat alpha("Alpha", 1);
	Bureaucrat beta("Beta", 150);
	newline();
	alpha.signForm(bushForm);
	try {
		bushForm.execute(beta);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		beta.executeForm(bushForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	
}


void robotomy_valid_tests() {
	try {
		RobotomyRequestForm randoForm;
		newline();
		RobotomyRequestForm cyborgForm("Cyborg");
		newline();
		Bureaucrat alpha("Alpha", 1);
		newline();
		
		randoForm.beSigned(alpha);
		alpha.signForm(cyborgForm);
		newline();

		// execute + executeForm with valid bureaucrat
		randoForm.execute(alpha);
		alpha.executeForm(cyborgForm);
		newline();

	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void unsigned_robotomy_tests() {
	RobotomyRequestForm cyborgForm("Cyborg");
	newline();
	Bureaucrat alpha("Alpha", 150);
	newline();
	// executeForm with unsigned form
	try {
		alpha.executeForm(cyborgForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	newline();
	// execute with unsigned form
	try {
		cyborgForm.execute(alpha);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void weak_bureaucrat_robotomy_tests() {
	RobotomyRequestForm cyborgForm("Cyborg");
	newline();
	Bureaucrat alpha("Alpha", 1);
	Bureaucrat beta("Beta", 150);
	newline();
	alpha.signForm(cyborgForm);
	try {
		cyborgForm.execute(beta);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		beta.executeForm(cyborgForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}


void presidential_valid_tests() {
	try {
		PresidentialPardonForm randoForm;
		newline();
		PresidentialPardonForm obamaForm("Obama");
		newline();
		Bureaucrat alpha("Alpha", 1);
		newline();
		
		randoForm.beSigned(alpha);
		alpha.signForm(obamaForm);
		newline();

		// execute + executeForm with valid bureaucrat
		randoForm.execute(alpha);
		alpha.executeForm(obamaForm);
		newline();

	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void unsigned_presidential_tests() {
	PresidentialPardonForm obamaForm("Obama");
	newline();
	Bureaucrat alpha("Alpha", 150);
	newline();
	// executeForm with unsigned form
	try {
		alpha.executeForm(obamaForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	newline();
	// execute with unsigned form
	try {
		obamaForm.execute(alpha);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void weak_bureaucrat_presidential_tests() {
	PresidentialPardonForm obamaForm("Obama");
	newline();
	Bureaucrat alpha("Alpha", 1);
	Bureaucrat beta("Beta", 150);
	newline();
	alpha.signForm(obamaForm);
	try {
		obamaForm.execute(beta);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		beta.executeForm(obamaForm);
		newline();
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

int main() {
	// shrubbery_valid_tests();
	// separator();
	// unsigned_shrubbery_tests();
	// separator();
	// weak_bureaucrat_shrubbery_tests();

	// robotomy_valid_tests();
	// separator();
	// unsigned_robotomy_tests();
	// separator();
	// weak_bureaucrat_robotomy_tests();

	// presidential_valid_tests();
	// separator();
	// unsigned_presidential_tests();
	// separator();
	// weak_bureaucrat_presidential_tests();
}
