/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:02:55 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/13 11:02:55 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
    static int index;

    this->_accountIndex = index;
    this->_nbDeposits = 0;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex 
        << ";amount:" << this->_amount 
        << ";created" << std::endl;

    index++;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";closed" << std::endl;
}

// the destructors are called in a reversed fashion (last in, first out principle)
// this is a fundamental characteristic of how C++ deals with the lifetime of objects

int Account::getNbAccounts() {
    return (_nbAccounts);
}
// you can't use this-> on static functions

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";deposit:" << deposit;

    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_amount += deposit;
    this->_totalAmount += deposit;

    std::cout << ";amount:" << this->_amount
        << ";nb_deposits:" << this->_nbDeposits
        << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
        << ";p_amount:" << this->_amount;

    if (withdrawal > this->_amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;

    std::cout << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
    return (true);
}

void Account::_displayTimestamp() {
	std::time_t rawTime;
	struct std::tm* timeInfo; // this struct holds broken-down components of day and time
	char time_buffer[80];

	std::time(&rawTime); // get the current time
	timeInfo = std::localtime(&rawTime); // convert to local time
	std::strftime(time_buffer, sizeof(time_buffer), "[%Y%m%d_%H%M%S]", timeInfo); // format the time

	std::cout << time_buffer;
}

void Account::displayAccountsInfos () {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void Account::displayStatus () const {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << this->_nbWithdrawals
        << std::endl;
}
