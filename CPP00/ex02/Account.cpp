#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    static int i;

    _displayTimestamp();
    std::cout << "index:" << i << ";amount:" << _amount << ";created" << std::endl;
    _accountIndex = i;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    i++;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    bool accepted(0);
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount - withdrawal > 0)
    {
        _amount -= withdrawal;
        accepted = 1;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
    }
    if (accepted)
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    else
        std::cout << ";withdrawal:refused" << std::endl;
    return (accepted);
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int		Account::checkAmount(void) const
{
    return (1);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "account:" << getNbAccounts() << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void)const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposit:" << _nbDeposits 
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    int year, month, day;
    std::time_t current = std::time(NULL);
    std::tm* now = std::localtime(&current);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    std::cout << "[" << year << std::setw(2) << std::setfill('0') << month;
    std::cout << std::setw(2) << std::setfill('0') << day << "_" ;
    std::cout << std::setw(2) << std::setfill('0') << now->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << now->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}