/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:43:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/12/10 00:42:40 by rsoo             ###   ########.fr       */
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

template <typename container>
void PmergeMe::fordJohnsonAlgorithm( container& c ) {
	(void)c;
	return ;
}

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

void PmergeMe::printOutput( char **av ) {
	int i = 1;
	std::cout << CYAN << "Unsorted Input Sequence:";
	while (av[i])
		std::cout << av[i++] << " ";
	std::cout << std::endl;

	// print the sorted elements in the containers:
	printContainerElements(_vec, "Vector");
	printContainerElements(_lst, "List");
}

template <typename container>
void PmergeMe::printContainerElements( container& c, const std::string& containerName ) {
	typename container::iterator it = c.begin();

	std::cout << GREEN << "Sorted Output Sequence (" << containerName << "): ";
	while (it != c.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

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

std::vector<int>& PmergeMe::getVec() {
	return _vec;
}

std::list<int>& PmergeMe::getLst() {
	return _lst;
}

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
