/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:19:41 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/30 01:19:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

void print_ind( int found_index ) {
    std::cout << UCYN "The target is in index: " << found_index << RESET << std::endl;
}

void vector_test() {
    try {
        int arr[7] = {-2, -1, 0, 1, 2, 3, 4};
        std::vector<int> vec;

        for (int i = 0; i < 7; i++) {
            vec.push_back(arr[i]);
        }
        print_ind(easyfind(vec, 4));
        print_ind(easyfind(vec, -2));
        print_ind(easyfind(vec, 0));
        print_ind(easyfind(vec, 5));
    } catch ( std::exception const& e ) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void deque_test() {
    try {
        int arr[7] = {25, -14, 15, 44, 0, -1234, 2};
        std::deque<int> deq;

        for (int i = 0; i < 7; i++) {
            deq.push_back(arr[i]);
        }
        print_ind(easyfind(deq, 44));
        print_ind(easyfind(deq, 2));
        print_ind(easyfind(deq, 0));
        print_ind(easyfind(deq, 5));
    } catch ( std::exception const& e ) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void list_test() {
    try {
        int arr[7] = {-52, 76, -33, 17, 45, -91, 8};
        std::list<int> lst;

        for (int i = 0; i < 7; i++) {
            lst.push_back(arr[i]);
        }
        print_ind(easyfind(lst, 8));
        print_ind(easyfind(lst, -91));
        print_ind(easyfind(lst, 45));
        print_ind(easyfind(lst, 0));
    } catch ( std::exception const& e ) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

int main() {
    vector_test();
    deque_test();
    list_test();
}
