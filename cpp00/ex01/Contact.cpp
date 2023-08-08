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

Contact::setIndex(int index) {
    this->index = index;
}

Contact::setInfo() {
    std::string temp;

    std::cout << "Please enter your" << std::endl;

    std::cout << "First Name:"
    std::cin >> temp;
    this->firstName = temp;

    std::cout << "Last Name:"
    std::cin >> temp;
    this->lastName = temp;

    std::cout << "Nickname:"
    std::cin >> temp;
    this->nickname = temp;

    std::cout << "Phone Number:"
    std::cin >> temp;
    this->phoneNumber= temp;

    std::cout << "Darkest Secret:"
    std::cin >> temp;
    this->darkestSecret = temp;
}
