/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:13:04 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 15:26:39 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

void newline() {
	std::cout << std::endl;
}

void separator() {
	std::cout << "______________________________________________________________" << std::endl;
}

void pdf_test() {
	const Animal* j = new Dog();
	newline();
	const Animal* i = new Cat();
	newline();

	delete j;
	delete i;
	separator();
}

void array_test() {
	Animal* animals[10];

	for (int i = 0; i < 9; i++) {
		if (i < 4) {
			animals[i] = new Dog();
			newline();
		} else {
			animals[i] = new Cat();
			newline();
		}
	}
	for (int i = 0; i < 9; i++) {
		delete animals[i];
	}
	separator();
}

// shallow copy:
// - copies the reference to the original Brain, so all copied Brains
// 	 share the same address
// - deep copy = creates an entirely new 
void cat_dog_test() {
	Cat kat;
	newline();
	Cat kat2( kat );
	newline();
	Cat kat3;
	newline();
	kat3 = kat;
	newline();

	std::cout << "Brain address 1: " << kat.getBrain() << std::endl;
	std::cout << "Brain address 2: " << kat2.getBrain() << std::endl;
	std::cout << "Brain address 3: " << kat3.getBrain() << std::endl;

	separator();
	
	Dog dawg;
	newline();
	Dog dawg2( dawg );
	newline();
	Dog dawg3;
	newline();
	dawg3 = dawg;
	newline();

	std::cout << "Brain address 1: " << dawg.getBrain() << std::endl;
	std::cout << "Brain address 2: " << dawg2.getBrain() << std::endl;
	std::cout << "Brain address 3: " << dawg3.getBrain() << std::endl;

	separator();
}

void wrong_cat_test() {
	WrongCat tak;
	newline();
	WrongCat tak2(tak);
	newline();
	WrongCat tak3;
	newline();
	tak3 = tak;
	newline();

	std::cout << "Brain address 1: " << tak.getBrain() << std::endl;
	std::cout << "Brain address 2: " << tak2.getBrain() << std::endl;
	std::cout << "Brain address 3: " << tak3.getBrain() << std::endl;
	
	separator();
}

int main()
{
	// pdf_test();
	// array_test();
	// cat_dog_test();
	// wrong_cat_test();
	// system("leaks Brain");
	return 0;
}
