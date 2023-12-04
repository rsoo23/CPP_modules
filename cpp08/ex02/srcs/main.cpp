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

#include "MutantStack.h"

void pdf_test() {
    MutantStack<int> mstack;

	mstack.push(5);
    mstack.push(17);
	std::cout << "Top of stack:" << std::endl;
    std::cout << mstack.top() << std::endl << std::endl;

    mstack.pop();

	std::cout << "Size of stack:" << std::endl;
    std::cout << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
	std::cout << "Second: " << *it << std::endl;
    --it;
	std::cout << "First: " << *it << std::endl << std::endl;
	std::cout << "Contents of stack: " << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void own_test() {
	MutantStack<char> mstack;

	mstack.push('b');
	mstack.push('r');
	mstack.push('e');
	mstack.push('a');
	mstack.push('d');
	mstack.push('s');
	std::cout << "Top of stack:" << std::endl;
    std::cout << mstack.top() << std::endl << std::endl;

	std::cout << "Size of stack:" << std::endl;
    std::cout << mstack.size() << std::endl << std::endl;

	while (!mstack.empty()) {
    	std::cout << mstack.top() << " is popped" << std::endl;
		mstack.pop();
	}
}

int main() {
    // pdf_test();
	own_test();
}
