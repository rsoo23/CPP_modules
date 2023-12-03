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

#include "Span.h"

void pdf_test() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void empty_span_test() {
    try {
        Span sp;

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

void one_element_test() {
    try {
        Span sp(1);

        sp.addNumber(23);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

void add_beyond_capacity_test() {
    try {
        Span sp(4);

        sp.addNumber(23);
        sp.addNumber(24);
        sp.addNumber(25);
        sp.addNumber(26);
        sp.addNumber(27);
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

void uint_limit_test() {
    try {
        Span sp(4);

        sp.addNumber(-2147483648);
        sp.addNumber(2147483647);
        // sp.addNumber(-1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

void int_limit_test() {
    try {
        Span sp(2);

        sp.addNumber(-2147483649);
        sp.addNumber(2147483648);
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

void random_num_test(int min, int max, int numberOfNumbers) {
    // seed the rng
    std::srand(std::time(0));

    // create a vector to store the random values
    std::vector<int> val;
    for (int i = 0; i < numberOfNumbers; i++) {
        int randomNum = min + std::rand() % (max - min + 1);
        val.push_back(randomNum);
    }

    Span sp(numberOfNumbers);

    sp.addMultipleNumbers(val.begin(), val.end());
    sp.printSortedElements();
    sp.printMinElement();
    sp.printMaxElement();
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main() {
    // pdf_test();
    // empty_span_test();
    // one_element_test();
    // add_beyond_capacity_test();
    // uint_limit_test();
    // int_limit_test();
    // random_num_test(-10000, 10000, 20000);
}
