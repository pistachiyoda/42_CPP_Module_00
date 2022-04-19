#include <iostream>
#include <iomanip>
#include <time.h>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;

    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;
}

Account::~Account()
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->_amount)
    {
        this->_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << this->_amount << ";";
        std::cout << "withdrawal:"
                  << "refused" << std::endl;
        return false;
    }
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    this->_amount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbWithdrawals++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    return true;
}

int Account::checkAmount(void) const
{
    return (0);
}

void Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t t = time(nullptr);
    const tm *localTime = localtime(&t);
    std::cout << "[";
    std::cout << localTime->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << localTime->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << localTime->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    std::cout << "] ";
}

Account::Account(void)
{
}