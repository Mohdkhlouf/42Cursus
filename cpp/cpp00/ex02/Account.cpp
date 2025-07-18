#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_totalAmount += this->_amount;
	std::cout << "index:" <<this->_accountIndex 
				<< ";amount:" << this->_amount << ";created\n";
	Account::_nbAccounts++;
};

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" <<this->_accountIndex 
				<< ";amount:" << this->_amount << ";closed\n";

};

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
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::_totalAmount << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount;
	this->_amount += deposit;
	Account::_totalAmount+=deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout<<";deposit:"<<deposit<<";amount:"<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;

}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount-=withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout<<";withdrawal:"<<withdrawal<<";amount:"<<this->_amount<<";nb_withdrawals:"<<this->_nbWithdrawals <<std::endl;
		return (true);
	}
	std::cout<<";withdrawal:refused"<<std::endl;
	return (false);
}

	void	Account::displayStatus() const
	{
		Account::_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount
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
