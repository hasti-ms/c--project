#include<iostream>
#include<string>
using namespace std;

class bankaccount{
	protected:
    int accountnumber;
	string accountholdername;
	double balance;
	
	public:
		bankaccount(int an, string n, double b) : accountnumber(an), accountholdername(n), balance(b){
		}
		virtual void diposit(double ammount){
			balance += ammount;
		}
		virtual void withdraw(double amount){
			if (amount <= balance){
				balance -= amount;
			}else{
				cout<<"insufficient funds!"<<endl;
			}
		}
		double getbalance(){
			return balance;
		}
		virtual void displayaccountinfo(){
			cout<<"account no.:"<<accountnumber<<endl;
			cout<<"name:"<<accountholdername<<endl;
			cout<<"balance:"<<balance<<endl;
		}
	virtual ~bankaccount(){
	}
};

class savingsaccount : public bankaccount{
	private:
		double interestrate;
	
	public:
		savingsaccount(int an, string n, double b, double r) : bankaccount(an, n, b), interestrate(r){
		}
		void calculateinterest(){
			double i= balance*(interestrate/100);
			cout<<"interest earned:"<<i<<endl;
		}
};

class checkingaccount : public bankaccount{
	private:
		double overdraftlimit;
	
	public:
		checkingaccount(int an, string n, double b, double ol) : bankaccount(an, n, b),overdraftlimit(ol){
		}
		void withdraw(double amount) override{
			if(amount <= (balance + overdraftlimit)){
				balance -= amount;
			}else{
				cout<<"transction denied!!"<<endl;
			}
			
		}
};

class fixedepositaccount : public bankaccount{
	private:
		int term;
	
	public:
	fixedepositaccount(int an, string n, double b, int t) : bankaccount(an, n, b),term(t){
		}
		void displayaccountinfo() override{
		    cout<<"[fixed]";
		    bankaccount::displayaccountinfo();
		    cout<<"term:"<<term<<"months"<<endl;
		}
};

int main()
{
	bankaccount *accounts[10];
	int count=0, choice;
	
	int an;
	string n;
	double b, extra;
	int months;
	do{
		cout<<"\n--- bank management system ---"<<endl;
		cout<<"1. add savings"<<endl;
		cout<<"2.add checking"<<endl;
		cout<<"3. add fixed deposit"<<endl;
		cout<<"4. show all"<<endl;
		cout<<"5. exit"<<endl;
		cout<<"enter choice:";
		cin>>choice;
		
		switch (choice){
			case 1:
				cout<<"account no.:";
				cin>>an;
				cout<<"name:";
				cin>>n;
				cout<<"balance:";
				cin>>b;
				cout<<"interest rate:";
				cin>>extra;
				accounts[count++]=new savingsaccount(an,n,b,extra);
				break;
			case 2:
				cout<<"account no.:";
				cin>>an;
				cout<<"name:";
				cin>>n;
				cout<<"balance:";
				cin>>b;
				cout<<"overdraft limit:";
				cin>>extra;
				accounts[count++]=new checkingaccount(an,n,b,extra);
				break;
			case 3:
				cout<<"account no.:";
				cin>>an;
				cout<<"name:";
				cin>>n;
				cout<<"balance:";
				cin>>b;
				cout<<"term:";
				cin>>extra;
				accounts[count++]=new fixedepositaccount(an,n,b,extra);
				break;
			case 4:
				cout<<"\n--account list--"<<endl;
				for(int i=0; i<count; i++){
					accounts[i]->displayaccountinfo();
				}
				break;
			
		}
	}while(choice!=5);
	
}
/*
--- bank management system ---
1. add savings
2.add checking
3. add fixed deposit
4. show all
5. exit
enter choice:1
account no.:101
name:alice
balance:10000
interest rate:0.05

--- bank management system ---
1. add savings
2.add checking
3. add fixed deposit
4. show all
5. exit
enter choice:2
account no.:102
name:bob
balance:500
overdraft limit:200

--- bank management system ---
1. add savings
2.add checking
3. add fixed deposit
4. show all
5. exit
enter choice:3
account no.:103
name:clara
balance:5000000
term:12

--- bank management system ---
1. add savings
2.add checking
3. add fixed deposit
4. show all
5. exit
enter choice:4

--account list--
account no.:101
name:alice
balance:10000
account no.:102
name:bob
balance:500
[fixed]account no.:103
name:clara
balance:5e+06
term:12months

--- bank management system ---
1. add savings
2.add checking
3. add fixed deposit
4. show all
5. exit
enter choice:5
*/