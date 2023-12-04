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

#include "Array.h"
#define MAX_VAL 750

void subject_provided_test() {
	// check to see if the implemented Array behaves the same as a standard array
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	// assigns random values to the arrays
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // tests if the copy and copy assign constructors work
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	// tests if all the elements in both arrays are equivalent
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
	// out of range tests
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void empty_array_test() {
    try {
        Array<int> arr;
        std::cout << UPUR "array size: " << arr.size() << RESET << std::endl;
        std::cout << UPUR << arr[0] << RESET << std::endl;
    } catch(std::exception const& e) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void sized_array_test() {
    try {
        Array<int> arr(5);
        arr[0] = 100;
        arr[1] = 200;   
        arr[2] = 300;
        arr[3] = 400;
        arr[4] = 500;

        std::cout << UYEL "array size: " << arr.size() << RESET << std::endl;
        std::cout << arr << std::endl;
        // out of bounds:
        std::cout << UPUR << arr[5] << RESET << std::endl;
    } catch (std::exception const& e) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void copy_test() {
    try {
        Array<double> arr(5);
        arr[0] = 1.123;
        arr[1] = 2.123;   
        arr[2] = 3.123;
        arr[3] = 4.123;
        arr[4] = 5.123;

        // copying arr into arr2
        Array<double> arr2( arr );
        std::cout << "arr2: " << std::endl;
        std::cout << UYEL "array size: " << arr2.size() << RESET << std::endl;
        std::cout << arr2 << std::endl;

        // deep copy: demonstrates that changing a value in the copied array 
        // will not change the corresponding value in the original array vice versa
        arr2[0] = 50.01;
        std::cout << "arr: " << std::endl;
        std::cout << arr << std::endl;
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;
    
        arr[4] = 50.01;
        std::cout << "arr: " << std::endl;
        std::cout << arr << std::endl;
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;
    } catch (std::exception const& e) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void copy_assignment_test() {
    try {
        Array<char> arr(3);
        arr[0] = 'a';
        arr[1] = 'b';   
        arr[2] = 'c';

        // copying arr into arr2
        Array<char> arr2;

        arr2 = arr;
        std::cout << "arr2: " << std::endl;
        std::cout << UYEL "array size: " << arr2.size() << RESET << std::endl;
        std::cout << arr2 << std::endl;

        // deep copy: demonstrates that changing a value in the copied array 
        // will not change the corresponding value in the original array vice versa
        arr2[0] = 'd';
        std::cout << "arr: " << std::endl;
        std::cout << arr << std::endl;
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;

        arr[2] = 'e';
        std::cout << "arr: " << std::endl;
        std::cout << arr << std::endl;
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;
    } catch (std::exception const& e) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

void complex_type_test() {
    try {
        Array<Complex> arr;
        Array<Complex> arr2(3);

        std::cout << UPUR "array size: " << arr.size() << RESET << std::endl;
        std::cout << UPUR "array size: " << arr2.size() << RESET << std::endl;
        arr2[0].set(2, 0);
        arr2[1].set(2, -2);
        arr2[2].set(2, 2);
        std::cout << arr2 << std::endl;

        // copy 
        Array<Complex> arr3( arr2 );
        arr3[0].set(5, 5);
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;
        std::cout << "arr3: " << std::endl;
        std::cout << arr3 << std::endl;

        // copy assignment
        arr = arr2;
        arr[0].set(6, 6);
        std::cout << "arr: " << std::endl;
        std::cout << arr << std::endl;
        std::cout << "arr2: " << std::endl;
        std::cout << arr2 << std::endl;
    } catch(std::exception const& e) {
        std::cout << URED << e.what() << RESET << std::endl;
    }
}

int main() {
	subject_provided_test();
    // empty_array_test();
    // sized_array_test();
    // copy_test();
    // copy_assignment_test();
    // complex_type_test();
    system("leaks array");
}
