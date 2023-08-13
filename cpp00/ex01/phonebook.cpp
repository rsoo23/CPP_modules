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

// CONSTRUCTOR
PhoneBook::PhoneBook() {
    for (int i = 0; i < 8; i++) {
        this->contactArr[i] = Contact();
    }
    this->number_of_contacts = 0;
};

// DESTRUCTOR
PhoneBook::~PhoneBook() {};


void	PhoneBook::Add() {
    static int  index;

    this->contactArr[index % 8].setIndex(index % 8);
    this->contactArr[index % 8].setInfo();
    this->number_of_contacts++;
    index++;
}

void PhoneBook::printInfoHeaderField() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::printAllContactRows() {
    int index = -1;
    int max_index;

    max_index = this->number_of_contacts;
    if (this->number_of_contacts > 8)
        max_index = 8;
    while (++index < max_index)
    {
        this->contactArr[index].printIndex();
		this->contactArr[index].printContactRow();
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
}

void    PhoneBook::getIndex() {
    int input_index;
    int max_index;
    bool exit = false;

    while (exit == false)
    {
        max_index = this->number_of_contacts;

        if (this->number_of_contacts > 8)
            max_index = 8;

        std::cout << "\e[0;34mPlease enter an index: \e[0m";
        if (!(std::cin >> input_index)) {
            std::cout << "\e[0;31mError: Only numeric inputs are allowed\e[0m" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        else if (input_index >= 0 && input_index < max_index) {
            std::cout << input_index << std::endl;

            this->printInfoHeaderField();
            this->contactArr[input_index].printIndex();
		    this->contactArr[input_index].printContactRow();
            std::cout << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            exit = true;
        }
        else
            std::cout << "\e[0;31mError: Index is out of scope\e[0m" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}

void	PhoneBook::Search() {
    if (this->number_of_contacts == 0)
    {
        std::cout << std::endl;
        std::cout << "\e[0;31mThere are no contacts in your phonebook :(\e[0m" << std::endl; 
        std::cout << std::endl;
        return ;
    }
	this->printInfoHeaderField();
    this->printAllContactRows();
    this->getIndex();
}
