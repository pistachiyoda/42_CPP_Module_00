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
    _accountIndex = Account::getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;

    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    _nbDeposits++;
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        std::cout << "withdrawal:"
                  << "refused" << std::endl;
        return false;
    }
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";";
    _nbWithdrawals++;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
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
