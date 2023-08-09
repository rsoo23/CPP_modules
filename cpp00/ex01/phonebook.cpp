/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:57:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/07 21:57:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

void	PhoneBook::InitPhoneBook() {
    for (int i = 0; i < 8; i++) {
        this->contactArr[i] = Contact();
    }
}

void	PhoneBook::Add() {
    static int  index;

    this->contactArr[index % 8].setIndex(index % 8);
    this->contactArr[index % 8].setInfo();
    index++;
}

void	PhoneBook::Search() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
	for (int index = 0;  this->contactArr[index])
	{
		this->contactArr[index].printContactRow();
		index++;
	}
}
