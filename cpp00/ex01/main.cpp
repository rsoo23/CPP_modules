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

#include "phonebook.hpp"
#include <string>

int main(void)
{
    std::string input;
    PhoneBook   MyPhoneBook;

    input = "";
    MyPhoneBook.InitPhoneBook();
    while (input != "EXIT")
    {
        std::cout << "Please enter one: ADD | SEARCH | EXIT" << std::endl;
        std::cin >> input;
        if (input == "ADD")
            MyPhoneBook.Add();
        else if (input == "SEARCH")
            MyPhoneBook.Search();
    }
}
