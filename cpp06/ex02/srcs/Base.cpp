/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:14:27 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 15:39:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.h"

Base::~Base() {}

Base* generate( void ) {
	std::srand(static_cast<unsigned>(std::time(nullptr)));
    int random_number = std::rand() % 3;

	sleep(1);
	if (random_number == 0) {
		A* instanceA = new A;
		std::cout << GREEN << "Class A generated" << RESET << std::endl;
		return instanceA;
	} else if (random_number == 1) {
		B* instanceB = new B;
		std::cout << GREEN << "Class B generated" << RESET << std::endl;
		return instanceB;
	} else {
		C* instanceC = new C;
		std::cout << GREEN << "Class C generated" << RESET << std::endl;
		return instanceC;
	}
}

void identify( Base* p ) {
	// the dynamic_cast returns a nullptr if it fails for pointers
	char res = '\0';

	if (dynamic_cast<A*>(p)) {
		res = 'A';
	} else if (dynamic_cast<B*>(p)) {
		res = 'B';
	} else if (dynamic_cast<C*>(p)) {
		res = 'C';
	}
	std::cout << CYAN << "dynamic_cast on a pointer, result: " << res << RESET << std::endl;
}

void identify( Base& p ) {
	// the dynamic_cast throws a std::bad_cast exception for references
	char res = '\0';

	try {
		A& casted_ref = dynamic_cast<A&>(p);
		(void)casted_ref;
		res = 'A';
	} catch (const std::bad_cast& ex) {}

	try {
		B& casted_ref = dynamic_cast<B&>(p);
		(void)casted_ref;
		res = 'B';
	} catch (const std::bad_cast& ex) {}
	
	try {
		C& casted_ref = dynamic_cast<C&>(p);
		(void)casted_ref;
		res = 'C';
	} catch (const std::bad_cast& ex) {}
	std::cout << PURPLE << "dynamic_cast on a reference, result: " << res << RESET;
}
