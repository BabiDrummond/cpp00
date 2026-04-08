#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ): 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout 
			<< " index:" << _accountIndex 
			<< ";amount:" << checkAmount() 
			<< ";created" 
			<< std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

Account::~Account ()
{
    _displayTimestamp();
    std::cout 
			<< " index:" << _accountIndex 
			<< ";amount:" << checkAmount() 
			<< ";closed" 
			<< std::endl;
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
			<< ";amount:" << checkAmount()
			<< ";nb_deposits:" << ++_nbDeposits
			<< std::endl;
	_totalAmount += _amount;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	_previousAmount;

	_previousAmount = _amount;
	_amount -= withdrawal;
	_displayTimestamp();
	if (_amount <= 0)
	{
		std::cout 
				<< " index:" << _accountIndex
				<< ";p_amount:" << _previousAmount
				<< ";withdrawal:refused"
				<< std::endl;
		_amount = _previousAmount;
		return (false);
	}
	std::cout 
			<< " index:" << _accountIndex
			<< ";p_amount:" << _previousAmount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << checkAmount()
			<< ";nb_withdrawals:" << ++_nbWithdrawals
			<< std::endl;
	_totalAmount -= _amount;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 
		<< " index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm* ltm = std::localtime(&now);

	std::cout
			<< "["
			<< 1900 + ltm->tm_year
			<< std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
			<< std::setw(2) << std::setfill('0') << ltm->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << ltm->tm_hour
			<< std::setw(2) << std::setfill('0') << ltm->tm_min
			<< std::setw(2) << std::setfill('0') << ltm->tm_sec
			<< "]";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}
