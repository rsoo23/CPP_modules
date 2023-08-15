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

Account::Account( int initial_deposit ) {
    static int index;

    this->_accountIndex = index;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_amount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex 
        << ";amount:" << this->_amount 
        << ";created" << std::endl;
    displayAccountsInfos();

    index++;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex 
        << ";amount:" << this->_amount 
        << ";closed" << std::endl;
}

static int Account::getNbAccounts() {
    return (this->_nbAccounts);
}

static int Account::getTotalAmount() {
    return (this->_totalAmount);
}

static int Account::getNbDeposits() {
    return (this->_totalNbDeposits);
}

static int Account::getNbWithdrawals() {
    return (this->_totalNbWithdrawals);
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
    if (withdrawal > _totalAmount) {
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

static void Account::_displayTimestamp() {

}

void Account::displayAccountsInfos () {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << this->_nbWithdrawals
        std::endl;
}

void Account::displayStatus () const {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
        << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits()
        << ";withdrawals:" << getNbWithdrawals()
        std::endl;
}
