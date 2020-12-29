// ConsoleApplication56.cpp : Defines the entry point for the console application.
//
/*

*/

#include "stdafx.h"
#include"Header.h"



Customer::Customer(){
	id = 0;
	name = new char[1];
	address = new char[1];
	name[0] = '/n';
	address[0] = '/n';
}
Customer::Customer(int i, char* n, char* a){
	name = new char[strlen(n) + 1];
	address = new char[strlen(a) + 1];
	strcpy(name, n);
	strcpy(address, a);
	id = i;
}
Customer& Customer::operator=(Customer const&c){
	if (this != &c){
		this->setAddress(c.getAddress());
		this->setName(c.getName());
		this->id = c.id;


	}
	return *this;


}
Customer::~Customer(){
	delete[]name;
	delete[]address;
}
void Customer::setName(char* a){
	name = new char[strlen(a) + 1];
	strcpy(name, a);
}
void Customer::setAddress(char* a){
	address = new char[strlen(a) + 1];
	strcpy(address, a);
}
void Customer::setId(int i){
	id = i;
}
char* Customer::getAddress()const{
	return address;
}
char* Customer::getName()const{
	return name;
}
int Customer::getid()const{
	return id;
} 
////////////////////////////////////////////////////////////////////////////////////
Account::Account(){
	iban = new char[1];
	ownerid = 0;
	amount = 0;
	iban[0] = '/n';
}
Account::Account(char* ib, int id, double a){
	iban = new char[strlen(ib) + 1];
	strcpy(iban, ib);
	ownerid = id;
	amount = a;
}
Account& Account::operator=(Account const &b){
	
	if (this != &b){
		this->ownerid = b.ownerid;
		this->amount = b.amount;
		this->iban = new char[strlen(b.iban) + 1];
		strcpy(this->iban, b.iban);
	}
	return *this;
}
Account::~Account(){
	delete[]iban;
}
double Account::getBalance()const{
	return amount;
}
void Account::setDeposit(double a){
	amount = amount + a;
}
void Account::setAmount(double a){
	amount = a;
}
bool Account::draw(double a){
	if (amount - a >= 0){
		amount = amount - a;
		return true;
	}
	return false;
}
char* Account::getIban()const{
	return iban;
}
int Account::getOwnerid()const{
	return ownerid;
}
void Account::setIban(char*a){
	iban = new char[strlen(a) + 1];
	strcpy(iban, a);
}
void Account::setOwnerid(int o){
	ownerid = o;
}
////////////////////////////////////////////////////////////////////////////
char* CurrentAccount::getaccType()const{
	return "CurrentAccount";
}
CurrentAccount::CurrentAccount(char*a, int b, double c) :Account(a, b, c){}
void CurrentAccount::deposit(double a){
	setDeposit(a);
}
CurrentAccount& CurrentAccount::operator=(CurrentAccount const& c){
	if (this != &c){
		
		this->setAmount(c.getBalance());
		this->setIban(c.getIban());
		this->setOwnerid(c.getOwnerid());
	}
	return *this;
}
char* CurrentAccount::getIbban()const{
	return getIban();
}
bool CurrentAccount::withdraw(double draw1){
	
	if (draw(draw1)){
		
		cout << "Done!" << endl;
		return true;
	}
	cout << "Not enough amount!" << endl;
	return false;
}
void CurrentAccount::showinfo()const{
	display();
	cout<< getIban() << " " << getOwnerid() << " " << getBalance() << endl;

}
void CurrentAccount::display()const{
	cout << "Current Account" << endl;
	cout << "Iban " << getIban() << endl << "OwnerID " << getOwnerid() << endl << "Balance " << getBalance() << endl<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
SavingAccount::SavingAccount(double a, char*b, int t, double l) :Account(b, t, l){
	interestRate = a;
}
SavingAccount& SavingAccount::operator=(SavingAccount const&s){
	if (this != &s){
		this->interestRate = s.interestRate;
		this->setAmount(s.getBalance());
		this->setIban(s.getIban());
		this->setOwnerid(s.getOwnerid());
	}
	return*this;
}
char* SavingAccount::getaccType()const{
	return "SavingAccount";
}
double SavingAccount::getinterestRate()const{
	return interestRate;
}
char* SavingAccount::getIbban()const{
	return getIban();
}
void SavingAccount::deposit(double a){
	setDeposit(a);
}
bool SavingAccount::withdraw(double draw1){
	
	if (draw(draw1)){
		
		cout << "Done!" << endl;
		return true;
	}
	cout << "Not enough amount!" << endl;
	return false;
}
void SavingAccount::display()const{
	cout << "Saving Account" << endl << "InterRate " << interestRate << endl;
	cout << "Iban " << getIban() << endl << "OwnerID " << getOwnerid() << endl << "Balance " << getBalance() << endl<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PivilegeAccount::PivilegeAccount(double a, char*c, int b, double d) :Account(c, b, d){
	overdraft = a;
}
PivilegeAccount& PivilegeAccount::operator=(PivilegeAccount const&p){
	if (this != &p){

		this->overdraft = p.overdraft;
		this->setAmount(p.getBalance());
		this->setIban(p.getIban());
		this->setOwnerid(p.getOwnerid());
	}
	return *this;
}
char* PivilegeAccount::getIbban()const{
	return getIban();
}
char* PivilegeAccount::getaccType()const{
	return "PrivilegeAccount";
}
void PivilegeAccount::deposit(double a){
	setDeposit(a);
}
void PivilegeAccount::display()const{
	cout << "Piviliege Account" << endl << "overdraft " << overdraft << endl;
	cout << "Iban " << getIban() << endl << "OwnerID " << getOwnerid() << endl << "Balance " << getBalance() << endl<<endl;
	
}
double  PivilegeAccount::getOverdraft()const{
	return overdraft;
}
bool PivilegeAccount::withdraw(double draw1){
	
	
	if (draw(draw1-getOverdraft())){
		setAmount(getBalance() - getOverdraft());
		cout << "Done!" << endl;
		return true;
	}
	cout << "Not enough amount!" << endl;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
Bank::Bank(char*a, char*b){
	name = new char[strlen(a)+1];
	address = new char[strlen(b )+1];
	strcpy(name, a);
	strcpy(address, b);
	cus = 0;
	acc = 0;
	accounts = new Account*[maxsizeacc];
	customers = new Customer[maxsizecus];
}
Bank::~Bank(){
	delete[]name;
	delete[]address;
}
char* Bank::getName()const{
	return name;
}
char* Bank::getAddress()const{
	return address;
}
void Bank::listCustomers()const{
	int i = 0;
	for (; i < cus; i++){
		cout << "Customer name " << customers[i].getName() << endl << "Customer id " << customers[i].getid() << endl
			<< "Customer address " << customers[i].getAddress() << endl<<endl;
	}
	if (i == 0){
		cout << "No customers!" << endl;
	}
}
void Bank::draw(double amm,char* iban){
	int i = 0;
	for (; i < acc; i++){

		if (strcmp(accounts[i]->getIban(), iban) == 0){
			if (accounts[i]->withdraw(amm)){
				
				break;
			}
			else{
				cout << "Draw error!" << endl;
				break;
			}
		}

	}
	if (i == acc){
		cout << "Account iban not found!" << endl;
	}

}
void Bank::deposit(double d, char*ibban){
	int i = 0;
	for (; i < acc; i++){

		if (strcmp(accounts[i]->getIban(), ibban) == 0){
			
				accounts[i]->deposit( d);
				cout << "Done!" << endl;
			
				break;
		}

	}
	if (i == acc){
		cout << "Account iban not found!" << endl;
	}

}
void Bank::addCustomer(int a, char* b, char * c){    //id,name,addr
	int i = 0;
	if (cus == maxsizecus){
		Customer*list = new Customer[maxsizecus * 2];
		for (int k = 0; k < cus; k++){
			list[k] = customers[k];

		}
		Customer*help = customers;
		customers = list;
		maxsizecus = maxsizecus * 2;
		for (int k = 0; k < cus; k++){
			help[k].~Customer();
		}
		
	}
	for (i; i < cus; i++){
		if (customers[i].getid() == a){
			cout << "Customer already exist!" << endl;
			break;
		}

	}
	if (i == cus){
		
		customers[cus].setId(a);
		customers[cus].setName(b);
		customers[cus].setAddress(c);
		cus++;
		cout << "Done!" << endl;
	}
}

void Bank::addAccount(char* a, char* b, int c,double d){         //acctype,iban,ownerid,amount
	int i = 0;
	if (acc == maxsizeacc){
		Account**list1 = new Account*[maxsizeacc * 2];

		for (int k = 0; k < acc; k++){
			list1[k] = accounts[k];

		}
		Account**help1 = accounts;
		accounts = list1;
		maxsizeacc = maxsizeacc * 2;
		delete help1;
	}
	for (i; i < cus; i++){
		
		if (customers[i].getid() == c){
			break;
		}

	}
	
	int y = 0;
	for (y; y < acc; y++){
		if (strcmp(accounts[y]->getIban(), b) == 0){
			cout << "Iban exists!" << endl;
			break;
		}

	}

	if (i != cus&&y==acc){
		
		if (strcmp(a, "PivilegeAccount") == 0){

			cout << "Add overdraft ";
			double o;
			cin >> o;
			PivilegeAccount *acc1=new PivilegeAccount(o, b, c, d);
			accounts[acc] = acc1;
			
			acc++;
			cout << "Done!" << endl;
		}
		else if (strcmp(a, "CurrentAccount") == 0){
			
			CurrentAccount *acc1=new CurrentAccount( b, c, d);
			accounts[acc] = acc1;
			
			acc++;
			cout << "Done!" << endl;
		}
		else if (strcmp(a, "SavingAccount") == 0){
			cout << "Enter interestrate " ;
			double inter;
			cin >> inter;
			SavingAccount *acc1=new SavingAccount(inter,b, c, d);
			accounts[acc] = acc1;
			acc++;
			cout << "Done!" << endl;
		}
		else{
			cout << "No such account type!" << endl;
		}
	}
	else{
		cout << "Error adding account!" << endl;
	}
}
void Bank::listAccounts()const{
	
	int i = 0;
	for (i; i < acc; i++){
		accounts[i]->display();
	}
	if (i == 0){
		cout << "No accounts to show!" << endl;
	}
}
void Bank::listCustomerAccount(int customerid)const{

	int i = 0;
	for (i; i < acc; i++){
		if (accounts[i]->getOwnerid() == customerid){
			accounts[i]->display();
			break;
		}
		
	}
	int y = 0;
	for (; y < cus; y++){
		if (customers[y].getid() == customerid){
			
			break;
		}

	}
	if (y==cus){
		cout << "No customer with id "<<customerid<<" found!" << endl;
	}
	else if (i == acc){
		cout << "No accounts found!" << endl;
	}

}
void Bank::transfer(char* from, char* to, double am){
	int i = 0;
	if (strcmp(from, to) != 0){
		for (i; i < acc; i++){
			if (strcmp(accounts[i]->getIban(), from) == 0){
				break;
			}
		}
		int y = 0;
		for (y; y < acc; y++){
			if (strcmp(accounts[y]->getIban(), to) == 0){
				break;
			}
		}
		if (i != acc&&y != acc){
			if (accounts[i]->withdraw(am)){
				accounts[y]->deposit(am);
				cout << "Transfer complete!" << endl;
			}
		}
		else{
			cout << "Transfer Error!" << endl;
		}
	}
	else{
		cout << "Transfer Error!" << endl;
	}
}
void Bank::display()const{
	cout << "Bank name : " << name << endl << "Bank address : " << address << endl << "Bank accounts : " 
		<< acc << endl << "Bank customers : " << cus << endl;
}
void Bank::deleteAccount(char* i){
	int y = 0;
	for (; y < acc; y++){
		if (strcmp(accounts[y]->getIban(), i) == 0){

			break;
		}
	}
	if (y != acc){
		Account*accs[1500];
		int count = 0;
		for (int u = 0; u < y; u++){

			accs[count] = accounts[u];
			count++;

		}
		for (int u = y + 1; u < acc; u++){

			accs[count] = accounts[u];
			count++;

		}
		acc--;

		for (int u = 0; u < acc; u++){

			accounts[u] = accs[u];

		}
		cout << "Account deleted!" << endl;
	}
	else{
		cout << "Account not found!" << endl;
	}
	
}
void Bank::deleteCustomer(int cusid){
	int i = 0,delid=0;
	for (; i < cus; i++){

		if (customers[i].getid() == cusid){
			
			break;
			
		}
	}
	if (i != cus){
		Customer custs[1500];
		int count = 0;
		for (int u = 0; u < i; u++){
			custs[count] = customers[u];
			count++;
		}
		for (int u = i + 1; u < cus; u++){
			custs[count] = customers[u];
			count++;
		}
		cus--;
		for (int u = 0; u < cus; u++){
			customers[u] = custs[u];
		}


		int y = 0;
		int count1 = 0;
		Account*accs[1500];
		for (; y < acc; y++){
			if (accounts[y]->getOwnerid() != cusid){
				
				accs[count1] = accounts[y];
				count1++;
				
			}
		}
		acc = count1;
		for (int u = 0; u < acc; u++){

			accounts[u] = accs[u];

		}
		cout << "Customer with id " << cusid << " deleted!" << endl;
	}
	else{
		cout << "Customer not found!" << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	char n [30];
	cout << "Enter bank name : ";
	cin.getline(n, 30);
	char addr[40];
	cout << "Enter bank address : ";
	cin.getline(addr, 40);
	Bank b(n, addr);

	int choice=0;
	while (choice != 12){
		cout << "-------------------------" << endl;
		cout << "1     List customers" << endl << "2     Add new customer" << endl << "3     Delete customer" << endl
			<< "4     List all accounts" << endl << "5     List customer accounts" << endl << "6     Add new aacounts" << endl
			<< "7     Delete aacount" << endl << "8     Withdraw from aacount" << endl << "9     Deposit to account" << endl
			<< "10    Transfer" << endl << "11    Display info for the bank" << endl << "12    Quit" << endl;
		cout << "-------------------------" << endl;
		cin >> choice;
		cin.ignore();
		if (!cin){
			cout << "Bad imput!" << endl;
			return 0;
		}
		switch (choice){

		case 1:b.listCustomers(); break;
		case 2:
			int id;
			char namecus[20];
			char addresscus[30];
			cout << "Enter cusstomer id(int) : ";
			cin >> id;
			
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			cout << "Enter cusstomer name : ";
			cin.getline(namecus, 20);
			cout << "Enter cusstomer address : ";
			cin.getline(addresscus, 20);

			b.addCustomer(id, namecus, addresscus);
			
			break;
		case 3:
			int cusid;
			cout << "Enter cusstomer id : ";
			cin >> cusid;
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			b.deleteCustomer(cusid);
			break;
		case 4: b.listAccounts(); break;
		case 5:
			int cusid1;
			cout << "Enter cusstomer id : ";
			cin >> cusid1;
			cin.ignore();
			b.listCustomerAccount(cusid1);
			break;
		case 6:
			//acctype,iban,ownerid,amount  char* a, char* b, int c,double d
			char type[20];
			char ibanacc [40];
			int ownerid;
			double amount;
			cout << "Enter owner id ";
			cin >> ownerid;
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			cout << "Enter account type( PivilegeAccount, SavingAccount, CurrentAccount ) : ";
			cin.getline(type, 20);
			cout << "Enter iban of account : ";
			cin.getline(ibanacc, 40);
			cout << "Enter amount : ";
			cin >> amount;
			cin.ignore();
			b.addAccount(type, ibanacc, ownerid, amount);
			
			break;
		case 7:
			char ibantodel[40];
			cout << "Enter iban to delete : ";
			cin.getline(ibantodel, 40);
			b.deleteAccount(ibantodel);
			
			break;
		case 8:
			double draw;
			cout << "Enter amount to draw : ";
			cin >> draw;
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			char ibantodraw[40];
			cout << "Enter iban : ";
			cin.getline(ibantodraw, 40);
			b.draw(draw, ibantodraw);
			
			break;
		case 9:
			double add;
			cout << "Enter amount for deposit : ";
			cin >> add;
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			char ibantodeposit[40];
			cout << "Enter iban : ";
			cin.getline(ibantodeposit, 40);
			b.deposit(add, ibantodeposit);
		
			break;
		case 10:
			char fromiban [40];
			char toiban[40];
			double ammounttotransfer;
			cout << "Enter source iban : ";
			cin.getline(fromiban, 40);
			cout << "Enter destination iban : ";
			cin.getline(toiban, 40);
			cout << "Enter amount : ";
			cin >> ammounttotransfer;
			cin.ignore();
			if (!cin){
				cout << "Bad imput!" << endl;
				return 0;
			}
			b.transfer(fromiban, toiban, ammounttotransfer);
			break;

		case 11:
			b.display(); break;
		case 12: return 0; break;

		}

	}


	return 0;

}

