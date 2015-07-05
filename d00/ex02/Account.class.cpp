// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int 	Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	return;
}

Account::Account (int initial_deposit)
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account ( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->checkAmount() > withdrawal)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		return true;
	}
	std::cout << "withdrawal:" << "refused";
	std::cout << std::endl;
	return false;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

int		Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int		Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}
int		Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp( void )
{
	time_t		now;
	struct tm	tstruct;
	char		buf[80];

	now = time(0);
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	std::cout << "[" << buf << "] ";
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;	
}

