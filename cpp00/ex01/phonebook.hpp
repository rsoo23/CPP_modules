/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:58:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/07 21:58:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void    InitPhoneBook();
        void    Add();
        void    Search();

    private:
        Contact contactArr[8];
};

#endif
