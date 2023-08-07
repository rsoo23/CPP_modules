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
#include <string.h>

int main(void)
{
    string      input;
    PhoneBook   MyPhoneBook;

    input = "";
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

// ADD
// Please enter: 
