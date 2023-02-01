/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:53:48 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:08:42 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "created" << std::endl;
    return ;
}

Account::~Account(void)
{
    Account::_nbAccounts--;
    this->_displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
    return ;
}

int Account::getNbAccounts(void)
{ return (Account::_nbAccounts); }

int Account::getTotalAmount(void)
{ return (Account::_totalAmount); }

int Account::getNbDeposits(void)
{ return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void)
{ return (Account::_totalNbWithdrawals); }

void Account::_displayTimestamp(void)
{
    std::time_t result = std::time(NULL);
    std::cout   << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<<  std::setw(2) << std::localtime(&result)->tm_mday
				<<  "_"
				<<  std::setw(2) << std::localtime(&result)->tm_hour
				<<  std::setw(2) << std::localtime(&result)->tm_min
				<<  std::setw(2) << std::localtime(&result)->tm_sec 
				<< "] " << std::flush;
    return ;
}

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
    return ;
}

void    Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    Account::_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";" << std::flush;
    this->_amount += deposit;
    std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
    return ;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:" << std::flush;
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal << ";" << std::flush;
   	this-> _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    std::cout	<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int     Account::checkAmount(void) const
{ return (this->_amount); }

void    Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout	<< "index:" << (this->_accountIndex) << ";"
				<< "amount:" << (this->_amount) << ";"
				<< "deposits:" << (this->_nbDeposits) << ";"
				<< "withdrawals:" << (this->_nbWithdrawals) << std::endl;
    return ;
}
