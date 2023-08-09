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

PhoneBook::PhoneBook() {
    for (int i = 0; i < 8; i++) {
        this->contactArr[i] = Contact();
    }
    this->number_of_contacts = 0;
};

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

void	PhoneBook::Search() {
    int index = -1;
    int input_index_str;

    if (this->number_of_contacts == 0)
    {
        std::cout << std::endl;
        std::cout << "\e[0;31mThere are no contacts in your phonebook :(\e[0m" << std::endl; 
        std::cout << std::endl;
        return ;
    }

	this->printInfoHeaderField();

    while (++index < this->number_of_contacts)
    {
        this->contactArr[index].printIndex();
		this->contactArr[index].printContactRow();
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

    while (1)
    {
        std::cout << "\e[0;34mPlease enter an index: \e[0m";
        std::cin >> input_index_str;
        std::cout << number_of_contacts << std::endl;
        if (input_index_str >= 0 && input_index_str < this->number_of_contacts)
        {
            this->printInfoHeaderField();
            this->contactArr[input_index_str].printIndex();
		    this->contactArr[input_index_str].printContactRow();
            std::cout << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            break ;
        }
        else
            std::cout << "\e[0;31mInvalid index. Please try again... \e[0m" << std::endl;
    }
}
