/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:43:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/12 00:33:25 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
	(void)other;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonAlgorithmVec() {
    int unpairedRemainder = -1;

	// if there is an odd number of elements, store the last element in unpairedRemainder
    if (_vec.size() % 2 != 0) {
        unpairedRemainder = _vec.back();
        _vec.pop_back();
    }

    // store all the values in a vector of pairs
	std::vector< std::pair<int, int> > pairs;
	getPairs(pairs, _vec);
	// std::cout << std::endl << "Grouped Pairs: " << std::endl;
	// printPairs(pairs);

    // sort pairs based on second value in the pair
	sortPairs(pairs);
	// std::cout << std::endl << "Sorted Pairs: " << std::endl;
	// printPairs(pairs);

    // split the pairs into two vectors: first values -> pend, second values -> main chain (_vec)
	sortIntoMainChain(_vec, pairs, unpairedRemainder);
}

void PmergeMe::fordJohnsonAlgorithmLst() {
    int unpairedRemainder = -1;

	// if there is an odd number of elements, store the last element in unpairedRemainder
    if (_lst.size() % 2 != 0) {
        unpairedRemainder = _lst.back();
        _lst.pop_back();
    }

    // store all the values in a vector of pairs
	std::list< std::pair<int, int> > pairs;
	getPairs(pairs, _lst);
	std::cout << std::endl << "Grouped Pairs: " << std::endl;
	printPairs(pairs);

    // sort pairs based on second value in the pair
	sortPairs(pairs);
	std::cout << std::endl << "Sorted Pairs: " << std::endl;
	printPairs(pairs);

    // split the pairs into two vectors: first values -> pend, second values -> main chain (_vec)
	sortIntoMainChain(_lst, pairs, unpairedRemainder);
}

template <typename P, typename T>
void PmergeMe::getPairs( P& pairs, const T& container ) {
	typename T::const_iterator it = container.begin();
	std::pair<int, int> pair;
	int n1;
	int n2;

	while (it != container.end()) {
		n1 = *it;
		it++;
		n2 = *it;
		it++;
		// ensures that the larger value is in the second value of the pair
		if (n1 > n2)
			pair = std::make_pair(n2, n1);
		else 
			pair = std::make_pair(n1, n2);
		pairs.push_back(pair);
	}
}

template <typename P>
void PmergeMe::sortPairs( P& pairs ) {
	typename P::iterator curr = pairs.begin();
	typename P::iterator temp1;
	typename P::iterator temp2;

	curr++;
	while (curr != pairs.end()) {
		temp1 = curr;
		temp2 = temp1;
		temp2--;
		while (temp2->second > temp1->second) {
			std::iter_swap(temp2, temp1);
			temp1--;
			if (temp1 == pairs.begin())
				break;
			temp2--;
		}
		curr++;
	}
}

template <typename T, typename P>
void PmergeMe::sortIntoMainChain( T& container, P& pairs, int unpairedRemainder ) {
	typename P::iterator it = pairs.begin();
	T pend;
	
	// clear the container, so that it can act as the main chain
	// push all the pairs' first values into pend, and the second values into main chain (container)
	container.clear();
	while (it != pairs.end()) {
		pend.push_back(it->first);
		container.push_back(it->second);
		it++;
	}
	// add the unpairedRemainder to pend if it exists
	if (unpairedRemainder != -1) {
		pend.push_back(unpairedRemainder);
	}
	// printContainerElements(pend, "pend");
	// printContainerElements(container, "container");
	
	// insert values from pend one by one into the main chain (container) by using lower_bound
	typename T::iterator pend_it = pend.begin();
	while (pend_it != pend.end()) {
		container.insert(std::lower_bound(container.begin(), container.end(), *pend_it), *pend_it);
		pend_it++;
	}
}

// time
void PmergeMe::startClock() {
	gettimeofday(&_startTime, NULL);
}

void PmergeMe::stopClock() {
	gettimeofday(&_endTime, NULL);
}

void PmergeMe::calculateDuration( const std::string& containerName ) {
	if (containerName == "vec") {
		_vecSortDuration = _endTime.tv_usec - _startTime.tv_usec;
	} else {
		_lstSortDuration = _endTime.tv_usec - _startTime.tv_usec;
	}
}

// printing
void PmergeMe::printOutput( char **av ) {
	int i = 1;
	std::cout << CYAN << "Unsorted Input Sequence: ";
	while (av[i])
		std::cout << av[i++] << " ";
	std::cout << std::endl << std::endl;

	// print the sorted elements in the containers:
	printContainerElements(_vec, "Vector");
	std::cout << std::endl;
	printContainerElements(_lst, "List");
	
	// print the durations
	std::cout << std::endl;
	std::cout << PURPLE "Time taken for std::vector: " << _vecSortDuration << " μs" << std::endl;
	std::cout << "Time taken for std::list: " << _lstSortDuration << " μs" << RESET << std::endl;
}

template <typename T>
void PmergeMe::printContainerElements( T& container, const std::string& containerName ) {
	typename T::iterator it = container.begin();

	std::cout << GREEN << "Sorted Output Sequence (" << containerName << "): ";
	while (it != container.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename P>
void PmergeMe::printPairs( P& pairs ) {
	typename P::iterator it = pairs.begin();

	while (it != pairs.end()) {
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;
		it++;
	}
}

// error checking
void PmergeMe::assignInputToContainers( int ac, char **av ) {
	for (int i = 1; i < ac; i++) {
		int j = 0;

		// checks for any non-digit characters
		while (av[i][j]) {
			if (av[i][j] == '-')
				j++;
			if (!isdigit(av[i][j++]))
				throw inputNotNumber();
		}

		// checks for negative numbers here instead of using another for loop to 
		// traverse vector again
		int num = atoi(av[i]);	
		if (num < 0)
			throw inputHasNegative();

		_vec.push_back(num);
		_lst.push_back(num);
	}
}

void PmergeMe::checkSorted() {
	std::vector<int> temp = _vec;
	std::sort(temp.begin(), temp.end());
	if (temp == _vec)
		throw inputIsSorted();
}

void PmergeMe::checkDuplicates() {
	for (long unsigned int i = 0; i < _vec.size(); i++) {
		for (long unsigned int j = i + 1; j < _vec.size(); j++) {
			if (_vec[i] == _vec[j])
				throw inputHasDuplicate();
		}
	}
}

// exceptions
const char* PmergeMe::inputHasDuplicate::what() const throw() {
	return "Error: The input sequence cannot have duplicates";
}

const char* PmergeMe::inputHasNegative::what() const throw() {
	return "Error: The input sequence cannot have negative numbers";
}

const char* PmergeMe::inputIsSorted::what() const throw() {
	return "Error: The input sequence is already sorted";
}

const char* PmergeMe::inputNotNumber::what() const throw() {
	return "Error: The input sequence cannot have non-digit characters";
}
