/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:40:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/18 17:16:55 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

void newline() {
	std::cout << std::endl;
}

void pdf_test() {
	IMateriaSource* src = new MateriaSource();
	newline();
	src->learnMateria(new Ice());
	newline();
	src->learnMateria(new Cure());
	newline();

	ICharacter* me = new Character("me");

	AMateria* tmp; // outputs nothing
	newline();
	tmp = src->createMateria("ice");
	newline();
	me->equip(tmp);
	newline();
	tmp = src->createMateria("cure");
	newline();
	me->equip(tmp);
	newline();

	ICharacter* bob = new Character("bob");
	newline();
	me->use(0, *bob);
	newline();
	me->use(1, *bob);
	newline();

	delete bob;
	delete me;
	delete src;
}

void overloaded_knowledge_test() {
	IMateriaSource* src = new MateriaSource();

	for (int i = 0; i < 5; i++) {
		src->learnMateria(new Ice());
		newline();
	}
	
	delete src;
}

void unknown_knowledge_test() {
	IMateriaSource* src = new MateriaSource();
	newline();
	src->learnMateria(new Ice());
	newline();

	ICharacter* me = new Character("me");

	AMateria* tmp; // outputs nothing
	newline();

	tmp = src->createMateria("cure");
	me->equip(tmp);
	newline();

	tmp = src->createMateria("Expecto Patronum!");
	me->equip(tmp);
	newline();
	
	delete src;
	delete me;
}

void overloaded_slot_test() {
	IMateriaSource* src = new MateriaSource();
	newline();
	src->learnMateria(new Ice());
	newline();
	src->learnMateria(new Cure());
	newline();

	ICharacter* me = new Character("me");

	AMateria* tmp; // outputs nothing
	newline();

	for (int i = 0; i < 5; i++) {
		tmp = src->createMateria("ice");
		me->equip(tmp);
		newline();
	}

	delete src;
	delete me;
}

void use_unequip_test() {
	// setup
	IMateriaSource* src = new MateriaSource();
	newline();

	src->learnMateria(new Cure());
	newline();

	ICharacter* me = new Character("me");

	AMateria* tmp; // outputs nothing
	newline();

	tmp = src->createMateria("cure");
	newline();
	me->equip(tmp);
	newline();

	ICharacter* bob = new Character("bob");
	newline();

	{ // use
		// normal
		me->use(0, *bob);
		newline();

		// empty slot
		me->use(1, *bob);
		newline();

		// out of range
		me->use(-3, *bob);
		newline();
	}
	{ // unequip
		// normal
		me->unequip(0);
		newline();

		// empty slot
		me->unequip(0);
		newline();

		// // out of range
		me->unequip(-3);
		newline();
	}

	delete bob;
	delete me;
	delete src;
}

void character_deep_copy_test() {
	// setup
	IMateriaSource* src = new MateriaSource();
	newline();

	src->learnMateria(new Cure());
	newline();

	Character legolas("legolas");

	AMateria* tmp; // outputs nothing
	newline();

	// equipping
	for (int i = 0; i < 4; i++) {
		tmp = src->createMateria("cure");
		newline();
		legolas.equip(tmp);
		newline();
	}

	// unequipping
	legolas.unequip(2);
	legolas.unequip(3);
	newline();

	// test
	Character archer1(legolas);
	newline();
	Character archer2;
	newline();
	archer2 = legolas;
	newline();

	std::cout << UPUR << "Address of Legolas' slots: " << legolas.getSlot() << std::endl;
	std::cout << UCYN << "Address of archer1's slots: " << archer1.getSlot() << std::endl;
	std::cout << UYEL << "Address of archer2's slots: " << archer2.getSlot() << RESET << std::endl;
	newline();
	
	std::cout << UPUR << "Address of Legolas' trash: " << legolas.getTrash() << std::endl;
	std::cout << UCYN << "Address of archer1's trash: " << archer1.getTrash() << std::endl;
	std::cout << UYEL << "Address of archer2's trash: " << archer2.getTrash() << RESET <<std::endl;
	newline();

	delete src;
}

int main() {
	pdf_test();
	// overloaded_knowledge_test();
	// unknown_knowledge_test();
	// overloaded_slot_test();
	// use_unequip_test();
	// character_deep_copy_test();
	system("leaks AMateria");
}
