/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:13:04 by rsoo              #+#    #+#             */
/*   Updated: 2023/10/15 21:38:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

int main()
{
	{
		// Animal Tests
		const Animal* meta = new Animal();

		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
		delete meta;
		std::cout << std::endl;
	}
	{
		// Dog Tests
		const Animal* j = new Dog();
		const Dog* dog = new Dog();

		std::cout << j->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		j->makeSound();
		dog->makeSound();
		delete j;
		delete dog;
		std::cout << std::endl;
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
		std::cout << std::endl;
	}
	{
		// WrongAnimal Tests
		const WrongAnimal* wrongAnimal = new WrongAnimal();

		std::cout << wrongAnimal->getType() << " " << std::endl;
		wrongAnimal->makeSound();
		delete wrongAnimal;
		std::cout << std::endl;
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
		std::cout << std::endl;
	}
	return 0;
}
