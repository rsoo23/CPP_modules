/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:58:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/07 21:58:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// access keywords: 
// - public: members are accessible outside the class
// - private: members cannot be accessed / viewed from outside the class
// - protected: members cannot be accessed / viewed from outside the class, but can be inherited

// attributes

// encapsulation:
// - better to do as often as you can
// - make sure that sensitive data is hidden from users
// - if you want to modify the value of a private member, you need to use get and set methods

class Contact {
    public:
        int     index;
        string  firstName;
        string  lastName;
        string  nickname;
        
        set_phone_number(int phone_num);
        set_darkest_secret(string str);

    private:
        int     phone_number;
        string  darkest_secret;
}

Contact::set_phone_number(int phone_num) {
    phone_number = phone_num;
}

Contact::set_darkest_secret(string str) {
    darkest_secret = str;
}

class PhoneBook {
    public:
        InitPhoneBook() {
            for (int i = 0; i < 8; ++i) {
                contactArr[i] = Contacts();
            }
        }
        Add();
        Search();
    private:
        Contacts contactArr[8];
}

PhoneBook::Add() {
    Pho
    std::cout << "Please enter your" << std::endl;
}

PhoneBook::Search() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Index     |First Name|Last Name |Nickname  |";
    std::cout << "---------------------------------------------" << std::endl;
}

// | 10 | 10 | 10 | 10 |

// #include <iostream>
// #include <string>

// class Contacts {
// public:
//     Contacts() : name(""), phoneNumber("") {}
//     Contacts(const std::string& name, const std::string& phoneNumber)
//         : name(name), phoneNumber(phoneNumber) {}

//     std::string getName() const { return name; }
//     std::string getPhoneNumber() const { return phoneNumber; }

// private:
//     std::string name;
//     std::string phoneNumber;
// };

// class Phonebook {
// public:
//     Phonebook() {
//         // Initialize contactsArray with default Contacts
//         for (int i = 0; i < 8; ++i) {
//             contactsArray[i] = Contacts();
//         }
//     }

//     // Other methods for adding, searching, and manipulating contacts

// private:
//     Contacts contactsArray[8]; // Array of Contacts with a size of eight
// };

// int main() {
//     Phonebook myPhonebook;

//     // Now you can interact with the myPhonebook instance and its contactsArray

//     return 0;
// }
