#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account()
{
	this->_amount = 0;
	this->_accountIndex = 0;
}
Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex++;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
};

Account::~Account() {};

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		return (true);
	}
	return (false);
}

	void	Account::displayStatus() const
	{
		Account::_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";amount"<<this->_amount
		<<";deposits:"<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;

	}
/*
this function display the current time
it reads it first as timestamp how many seconds till now from epoch 1970 years
then by datetime struct it chnages it to local time.
then ue the strftime to format to readdable time*/
void Account::_displayTimestamp(void)
{
	time_t timestamp;
	struct tm datetime;
	char output[50];

	timestamp = time(NULL);
	datetime = *localtime(&timestamp);
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}
