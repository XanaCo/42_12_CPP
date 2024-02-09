// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

/*CLASS STATIC VAR*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*CONSTRUCTORS & DESTRUCTORS*/

Account::Account(int initial_deposit) {

	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_displayTimestamp();
	std::cout << "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";created" << std::endl;
	Account::_nbAccounts++;

	return ;
}

Account::Account() {

	return ;
}

Account::~Account() {

	Account::_displayTimestamp();
	std::cout << "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";closed" << std::endl;

	return ;
}

/*MEMBER FUNCTIONS make*/

void	Account::makeDeposit(int deposit) {

	int	prev;

	prev = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< prev
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< this->_amount
				<< ";nb_deposits:"
				<< this->_nbDeposits
				<< std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	return ;
}

bool	Account::makeWithdrawal(int withdrawal) {

	int	prev;

	Account::_displayTimestamp();
	prev = this->_amount;
	std::cout << "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< prev
				<< ";withdrawal:";
	if (prev - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return 1;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal
				<< ";amount:"
				<< this->_amount
				<< ";nb_withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	return 0;
}

/*MEMBER FUNCTIONS get OR check*/

int		Account::checkAmount( void ) const {
	
	return this->_amount;
}

int	Account::getNbAccounts( void ) {

	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {

	return _totalAmount;
}

int	Account::getNbDeposits( void ) {

	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
}

/*MEMBER FUNCTIONS display*/

void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << "accounts:"
				<< Account::getNbAccounts()
				<< ";total:"
				<< Account::getTotalAmount()
				<< ";deposits:"
				<< Account::getNbDeposits()
				<< ";withdrawals:"
				<< Account::getNbWithdrawals()
				<< std::endl;

	return ;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;

	return ;
}

void	Account::_displayTimestamp( void ) {

	// std::cout << "[19920104_091532] ";
	
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[";
	std::cout << now->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw (2) << now->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw (2) << now->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw (2) << now->tm_hour;
	std::cout << std::setfill('0') << std::setw (2) << now->tm_min;
	std::cout << std::setfill('0') << std::setw (2) << now->tm_sec;
	std::cout << "] ";

	return ;
}
