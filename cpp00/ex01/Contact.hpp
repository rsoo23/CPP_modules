/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:10:55 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/08 22:10:55 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip> // header providing parametric manipulators
#include <iostream>
#include <string>
#include <cctype> // isdigit
#include <cstdlib> // atoi

class Contact {
    public:
        Contact();
        ~Contact();
        void setIndex(int index);
        void setInfo();
		void printContactRow();
        void printIndex();
		std::string trimString(std::string);

    private:
        int         index;
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif
