/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:21:36 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/08 21:21:36 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::string input;
    PhoneBook   MyPhoneBook;

    input = "";
    MyPhoneBook.InitPhoneBook();
    while (input != "EXIT")
    {
        std::cout << "Please enter one: \e[0;32mADD \e[0;37m| \e[0;34mSEARCH \e[0;37m| \e[0;31mEXIT\e[0m" << std::endl;
        std::cin >> input;
        if (input == "ADD")
            MyPhoneBook.Add();
        else if (input == "SEARCH")
            MyPhoneBook.Search();
    }
}
