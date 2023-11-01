/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:37:34 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/01 11:31:26 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

void newline() {
	std::cout << std::endl;
}

void constructor_tests() {
	Bureaucrat anonymous;
	Bureaucrat bruno("bruno", 100);
	Bureaucrat c( bruno );
	Bureaucrat d;

	d = c;

	std::cout << anonymous << std::endl;
	std::cout << bruno << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}

void constructor_grade_range_test() {
	try {
		Bureaucrat bruno("bruno", -1);
		std::cout << bruno << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat mars("mars", 200);
		std::cout << mars << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

void increment_decrement_test() {
	try {
		Bureaucrat mars("mars", 149);
		std::cout << mars << std::endl;
		mars.decrementGrade();
		std::cout << mars << std::endl;
		mars.decrementGrade();
		std::cout << mars << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
	newline();
	try {
		Bureaucrat mars("mars", 2);
		std::cout << mars << std::endl;
		mars.incrementGrade();
		std::cout << mars << std::endl;
		mars.incrementGrade();
		std::cout << mars << std::endl;
	} catch (std::exception& e) {
		std::cout << URED << e.what() << RESET << std::endl;
	}
}

int main() {
	// constructor_tests();
	// constructor_grade_range_test();
	increment_decrement_test();
}
