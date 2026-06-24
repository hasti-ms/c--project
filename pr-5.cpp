#include<iostream>
#include<string>
using namespace std;

class liberaryitem{
	private:
	string title;
	string author;
	string duedate;
	
	public:
		liberaryitem(string t, string a, string dd) : title(t), author(a), duedate(dd){
		}
		~liberaryitem(){
		}
		string gettitle() const{
			return title;
		}
		string getauthor() const{
			return author;
		}
		string getduedate() const{
			return duedate;
		}
        void settitle(string newtitle){
        	title = newtitle;
		}
		void setauthor(string newauthor){
        	author = newauthor;
		}
		void setduedate(string newduedate){
        	duedate = newduedate;
		}
		virtual void checkout() = 0;
		virtual void returnitem() = 0;
		virtual void displaydetails() const = 0;
};

class book : public liberaryitem{
	public:
	book( string t,  string a, string dd) : liberaryitem(t, a, dd){
	}
	 
	void checkout() override{
		cout<<"book"<<gettitle()<<"'checked out.'"<<endl;
	}
	void returnitem() override{
		cout<<"book"<<gettitle()<<"'returned.'"<<endl;
	}
	void displaydetails() const override{
		cout<<"title:"<< gettitle()<< "| author:"<<getauthor()<<"| due:"<<getduedate()<<endl;
	}
};

class dvd : public liberaryitem{
	int duration;
	
	public:
	dvd( string t, string a, string dd, int du) : liberaryitem(t, a, dd){
		duration=du;
	}
		void checkout() override{
		cout<<"DVD"<<gettitle()<<"'checked out.'"<<endl;
	}
	void returnitem() override{
		cout<<"DVD"<<gettitle()<<"'returned.'"<<endl;
	}
	void displaydetails() const override{
		cout<<"title:"<< gettitle()<< ",duration:"<<duration<<"min, due:"<<getduedate()<<endl;
	}
};

class magazines : public liberaryitem{
	int issuenumber;
	
	public:
	magazines( string t,  string a, string dd, int in) : liberaryitem(t, a, dd){
		issuenumber=in;
	}
		void checkout() override{
		cout<<"magazines"<<gettitle()<<"'checked out.'"<<endl;
	}
	void returnitem() override{
		cout<<"magazines"<<gettitle()<<"'returned.'"<<endl;
	}
	void displaydetails() const override{
		cout<<"title:"<< gettitle()<< ",issue number:"<<issuenumber<<"min, due:"<<getduedate()<<endl;
	}
};
 
const int maxitem = 10;

int main()
{
    liberaryitem *li[maxitem];
	int count=0;
	int choice; 
	
	do{
		cout<<"\n --- liberary management systrem ---\n";
		cout<<"1. add book\n";
		cout<<"2. add DVD\n";
		cout<<"3. add magazine\n";
		cout<<"4. display all items\n";
		cout<<"5. exit\n";
		cout<<"enter choice:";
		cin>>choice;
		cin.ignore();
		
	switch(choice){

		case 1:
		case 2:
		case 3:
			if (count < maxitem){
				string t, a, dd;
				
				cout << " title:";
				getline(cin, t);
				cout<<"author:";
				getline(cin, a);
				cout<<"due:";
				getline(cin, dd);
				
				if (choice == 1) li[count++] = new book(t, a, dd);
				else if (choice == 2){
					int du;
					cout<<"duration(mins) :";
					cin>>du;
					li[count++] = new dvd(t, a, dd, du);
				}else {
					int in;
					cout<<"issue number:";
					cin>>in;
					li[count++] = new magazines(t, a, dd, in);
				}
				cout<<"item added succesfully!!\n";
			}else {
				cout<<"liberary is full!!!\n";
			}
			break;
		case 4:
			for (int i=0; i<count; i++)
			li[i]->displaydetails();
			break;
		case 5:
			cout<<"exiting system.....\n";
			break;
		default:
			cout<<"invalid choice!!!";
		}
    }while (choice != 5);
    
    for( int i=0; i<count; i++)
    delete li[i];
    
}
/*
--- liberary management systrem ---
1. add book
2. add DVD
3. add magazine
4. display all items
5. exit
enter choice:1
 title:atomic habits
author:james clear
due:10/10/2026
item added succesfully!!

 --- liberary management systrem ---
1. add book
2. add DVD
3. add magazine
4. display all items
5. exit
enter choice:2
 title:music
author:no
due:10/10/2026
duration(mins) :10
item added succesfully!!

 --- liberary management systrem ---
1. add book
2. add DVD
3. add magazine
4. display all items
5. exit
enter choice:4
title:atomic habits| author:james clear| due:10/10/2026
title:music,duration:10min, due:10/10/2026

 --- liberary management systrem ---
1. add book
2. add DVD
3. add magazine
4. display all items
5. exit
enter choice:5
exiting system.....
*/