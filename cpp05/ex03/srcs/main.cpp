/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:37:34 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/02 10:30:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void newline() {
	std::cout << std::endl;
}

void separator() {
	std::cout << "_________________________________________________________________________________" << std::endl;
}

void intern_tests() {
	Intern rando;
	newline();
	AForm* shrubForm;
	AForm* roboForm;
	AForm* presForm;
	AForm* randomForm;

	shrubForm = rando.makeForm("Shrubbery Creation Form", "Amazon Forest");
	newline();
	roboForm = rando.makeForm("Robotomy Request Form", "Terminator");
	newline();
	presForm = rando.makeForm("Presidential Pardon Form", "Donald Trump");
	newline();
	randomForm = rando.makeForm("Random Form", "Target");
	newline();

	separator();
	Bureaucrat gamma("Gamma", 5);
	
	shrubForm->beSigned(gamma);
	shrubForm->execute(gamma);
	newline();
	roboForm->beSigned(gamma);
	roboForm->execute(gamma);
	newline();
	presForm->beSigned(gamma);
	presForm->execute(gamma);
	newline();

	delete shrubForm;
	delete roboForm;
	delete presForm;
}

int main() {
	intern_tests();
	system("leaks Bureaucrat");
}
