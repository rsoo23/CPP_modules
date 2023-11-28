/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:03:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 13:38:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

int main() {
	Data man;
	Data *received;
	uintptr_t ptr;

	man.name = "Bob Stevens";
	man.height = 170;
	man.weight = 70;
	man.age = 24;

	ptr = Serializer::serialize(&man);
	received = Serializer::deserialize(ptr);

	std::cout << GREEN << received->name << RESET << std::endl;
	std::cout << CYAN << received->height << RESET << std::endl;	
	std::cout << YELLOW << received->weight << RESET << std::endl;	
	std::cout << PURPLE << received->age << RESET << std::endl;	
}
