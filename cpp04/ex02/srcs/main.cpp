/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:13:04 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/16 16:30:18 by rsoo             ###   ########.fr       */
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
void deep_copy_test() {
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

void shallow_copy_test() {
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

void ex00_tests()
{
	{
		// Dog Tests
		const Animal* j = new Dog();
		const Dog* dog = new Dog();
		const Animal* s = j;

		std::cout << j->getType() << " " << std::endl;
		std::cout << s->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		j->makeSound();
		dog->makeSound();
		delete j;
		delete dog;
		separator();
	}	
	{
		// Cat Tests
		const Animal* i = new Cat();
		const Cat* cat = new Cat();

		std::cout << i->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		i->makeSound();
		cat->makeSound();

		delete i;
		delete cat;
		separator();
	}
	{
		// WrongAnimal Tests
		const WrongAnimal* wrongAnimal = new WrongAnimal();

		std::cout << wrongAnimal->getType() << " " << std::endl;
		wrongAnimal->makeSound();
		delete wrongAnimal;
		separator();
	}
	{	
		// WrongCat Tests
		const WrongAnimal* tac1 = new WrongCat();
		const WrongCat* tac2 = new WrongCat();

		std::cout << tac1->getType() << " " << std::endl;
		std::cout << tac2->getType() << " " << std::endl;
		tac1->makeSound();
		tac2->makeSound();

		delete tac1;
		delete tac2;
		separator();
	}
}

void ex01_tests() {
	pdf_test();
	array_test();
	deep_copy_test();
	shallow_copy_test();
}

// void abstract_instantiate_test() {
// 	// Animal Tests
// 	const Animal* meta = new Animal();

// 	std::cout << meta->getType() << " " << std::endl;
// 	meta->makeSound();
// 	delete meta;
// 	std::cout << std::endl;
// }

int main()
{
	// ex00_tests();
	// ex01_tests();
	// abstract_instantiate_test();
	system("leaks Abstract");
	return 0;
}
