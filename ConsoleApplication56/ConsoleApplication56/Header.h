
#include<iostream> 
using namespace std;
int maxsizecus = 2, maxsizeacc = 2;
class Customer{
	int id;
	char* name ;
	char* address ;
public:
	Customer(int, char*, char*);
	Customer();
	~Customer();
	int getid()const;
	char* getName()const;
	char* getAddress()const;
	void setName(char*);
	void setAddress(char*);
	void setId(int);
	Customer&operator=(Customer const&);
};
///////////////////////////////////////////////////////
class Account{

	char* iban ;
	int ownerid;
	double amount;

public:
	Account();
	Account(char*, int, double);
	~Account();
	Account& operator=(Account const&);
	virtual void deposit(double) = 0;
	virtual bool withdraw(double) = 0;
	virtual void display()const = 0;
	double getBalance()const;
	bool draw(double);
	char* getIban()const;
	int getOwnerid()const;
	void setIban(char*);
	void setDeposit(double);
	void setOwnerid(int);
	void setAmount(double);


};
//////////////////////////////////////////////////////////////
class CurrentAccount :public Account{


public:
	CurrentAccount(char*, int, double);
	void deposit(double);
	bool withdraw(double);
	void display()const;
	void showinfo()const;
	char*getaccType()const;
	char*getIbban()const;
	CurrentAccount&operator=(CurrentAccount const&);
};
////////////////////////////////////////////////////////////////
class SavingAccount : public Account{

	double interestRate;
public:
	SavingAccount(double, char*, int, double);
	double getinterestRate()const;
	void deposit(double);
	bool withdraw(double);
	void display()const;
	char*getaccType()const;
	char*getIbban()const;
	SavingAccount&operator=(SavingAccount const&);
};
////////////////////////////////////////////////////////////
class PivilegeAccount : public Account{
	double overdraft;
public:
	PivilegeAccount(double, char*, int, double);
	void deposit(double);
	bool withdraw(double);
	void display()const;
	double getOverdraft()const;
	char*getaccType()const;
	char*getIbban()const;
	PivilegeAccount& operator=(PivilegeAccount const&);
};
/////////////////////////////////////////////////////////////
class Bank{
	int cus, acc;
	char* name;
	char*address;
	Customer *customers;
	Account **accounts;
public:

	Bank(char*, char*);
	~Bank();
	char* getName()const;
	char* getAddress()const;
	void addCustomer(int, char*, char*);//id,name,addr
	void deleteCustomer(int);//id
	void addAccount(char*, char*, int, double);//acctype,iban,ownerid,amount
	void deleteAccount(char*);//iban
	void listAccounts()const;
	void listCustomerAccount(int)const;
	void listCustomers()const;
	void transfer(char*, char*, double);//fromiban,toiban,amount
	void display()const;
	void draw(double, char*);
	void deposit(double, char*);
};