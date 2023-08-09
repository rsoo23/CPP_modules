/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:10:44 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/08 22:10:44 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void	Contact::setIndex(int index) {
    this->index = index;
}

void	Contact::setInfo() {
    std::string temp;

    std::cout << "\e[0;32mPlease enter your:\e[0m" << std::endl;

    std::cout << "	First Name: ";
    std::cin >> temp;
    this->firstName = temp;

    std::cout << "	Last Name: ";
    std::cin >> temp;
    this->lastName = temp;

    std::cout << "	Nickname: ";
    std::cin >> temp;
    this->nickname = temp;

    std::cout << "	Phone Number: ";
    std::cin >> temp;
    this->phoneNumber= temp;

    std::cout << "	Darkest Secret: ";
    std::cin >> temp;
    this->darkestSecret = temp;
}

void    Contact::printIndex() {
    std::cout << "|" << std::setw(10) << std::right << this->index << "|";
}

std::string Contact::trimString(std::string str) {
    str.resize(9);
    str.resize(10, '.');
    return (str);
}

void	Contact::printContactRow() {
	if (this->firstName.length() > 10)
        this->firstName = this->trimString(this->firstName);
    std::cout << std::setw(10) << std::right << this->firstName << "|";

	if (this->lastName.length() > 10)
        this->lastName = this->trimString(this->lastName);
    std::cout << std::setw(10) << std::right << this->lastName << "|";

	if (this->nickname.length() > 10)
        this->nickname = this->trimString(this->nickname);

    std::cout << std::setw(10) << std::right << this->nickname << "|";
}
