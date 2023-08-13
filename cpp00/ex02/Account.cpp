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
    this->_amount = 0;
    this->_amount += initial_deposit;
}

Account::~Account() {
}

static int Account::getNbAccounts() {
    return (this->_nbAccounts);
}

static int Account::getTotalAmount() {
    return (this->_totalAmount);
}

static int Account::getNbDeposits() {
    return (this->_NbDeposits);
}

static int Account::getNbWithdrawals() {
    return (this->_NbWithdrawals);
}

void makeDeposit( int deposit ) {
    this->_nbDeposits = 1;
    this->_totalNbDeposits++;
    this->_amount += deposit;
    this->_totalAmount += deposit;
}

bool makeWithdrawal( int withdrawal ) {
    if (withdrawal > _totalAmount) {
        return (false);
    }
    this->_nbWithdrawals = 1;
    this->_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    return (true);
}

int checkAmount () const {
    return (this->_amount);
}

void displayStatus () const {

}
