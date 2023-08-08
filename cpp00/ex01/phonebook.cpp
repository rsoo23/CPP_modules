/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:57:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/07 21:57:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::InitPhoneBook() {
    for (int i = 0; i < 8; i++) {
        this->contactArr[i] = Contact();
    }
}

PhoneBook::Add() {
    static int  index;

    this->contactArr[index % 8].setIndex(index % 8);
    this->contactArr[index % 8].setInfo();
    index++;
}

PhoneBook::Search() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Index     |First Name|Last Name |Nickname  |";
    std::cout << "---------------------------------------------" << std::endl;
}
