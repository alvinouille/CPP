#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit), nbDeposits(0), _nbWithdrawals(0), _accountIndex(0)
{
    static int i;

    std::cout << "[date] index:" << i << ";amount:" << _amount << ";created" << std::endl;
    _accountIndex = i;
    _nbAccounts++;
    i++;
}

void	Account::makeDeposit(int deposit)
{
    std::cout << "[date] index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    bool accepted(0);
    
    std::cout << "[date] index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount - withdrawal > 0)
    {
        _amount -= withdrawal;
        accepted = 1;
        _nbWithdrawals++;
    }
    if (accepted)
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    else
        std::cout << ";withdrawal:refused" << std::endl;
}

Account::~Account(void)
{
    std::cout << "[date] index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

static int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}
static int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

static int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

static void	Account::displayAccountsInfos(void)
{
    std::cout << "[date] account:" << getNbAccounts() << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void)const
{
    std::cout << "[date] index:" << _accountIndex << ";amount:" << _amount << ";deposit:" << _nbDeposits 
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);