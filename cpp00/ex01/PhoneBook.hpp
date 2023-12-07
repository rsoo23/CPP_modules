/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:58:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 09:54:56 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void Add();
        void Search();
        void printInfoHeaderField();
        void printAllContactRows();
        void getIndex();

    private:
        int     number_of_contacts;
        Contact contactArr[8];
};

#endif
