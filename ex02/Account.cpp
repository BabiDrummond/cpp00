#include <iostream>
#include "Account.hpp"

Account::Account ( int initial_deposit ): 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account ()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts++;
}

void	Account::makeDeposit( int deposit )
{
	int	_previousAmount;

	_previousAmount = _amount;
	_amount += deposit;
	_displayTimestamp();
	std::cout 
			<< " index:" << _accountIndex
			<< ";p_amount:" << _previousAmount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << ++_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	_previousAmount;

	_previousAmount = _amount;
	_amount -= withdrawal;
	if (_amount <= 0)
	{
		std::cout 
		<< " index:" << _accountIndex
		<< ";p_amount:" << _previousAmount
		<< ";withdrawal:refused" << withdrawal
		<< std::endl;
		_amount = _previousAmount;
		return (false);
	}
	std::cout 
	<< " index:" << _accountIndex
	<< ";p_amount:" << _previousAmount
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << ++_nbWithdrawals
	<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{

}
