/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:37:34 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 15:04:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void newline() {
	std::cout << std::endl;
}

void constructor_tests() {
	Form a;
	Form b("form 1", 100, 120);
	Form c( b );
	Form d;

	d = c;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}

void constructor_grade_range_test() {
	try {
		Form a("form 1", -1, 120);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		Form a("form 1", 160, 120);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		Form a("form 1", 10, -1);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		Form a("form 1", 10, 160);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void signing_tests() {
	try {
		Form a("Holy Scroll", 30, 20);
		Form b("Holy Scroll 2", 30, 20);
		Form c("Holy Scroll 3", 30, 20);
		Form d("Holy Scroll 4", 30, 20);
		Bureaucrat god("Jesus", 1);
		Bureaucrat devil("Satan", 150);
		
		newline();

		// use beSigned on same form twice
		a.beSigned(god);
		a.beSigned(god);
		newline();

		// use signForm on same form twice
		god.signForm(b);
		god.signForm(b);
		newline();

		// use signForm using low level Bureaucrat 
		devil.signForm(c);
		newline();

		// use beSigned using low level Bureaucrat
		d.beSigned(devil);
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

int main() {
	constructor_tests();
	// constructor_grade_range_test();
	// signing_tests();
}
