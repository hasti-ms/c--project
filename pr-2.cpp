#include<iostream>
using namespace std;

class train{
	private:
		int trainnumber;
		char trainname[50];
		char source[50];
		char destination[50];
		char traintime[10];
		
	public:
		static int traincount;
		
	    train(){
			trainnumber=0;
		    trainname[0]='\0';
			source[0]='\0';
			destination[0]='\0';
			traintime[0]='\0';
		}
		train(int tnum, char tnm[], char s[], char d[], char tt[]){
			trainnumber=tnum;
			for(int i=0; i<50; i++){
				trainname[i]=tnm[i];
				trainname[i+1]='\0';
			}
			for(int i=0; i<50; i++){
				source[i]=s[i];
				source[i+1]='\0';
			}
			for(int i=0; i<50; i++){
				destination[i]=d[i];
				destination[i+1]='\0';
			}
			for(int i=0; i<50; i++){
				traintime[i]=tt[i];
				traintime[i+1]='\0';
			}
			traincount++;
		}
		
		~train(){
			traincount--;
		}
		int gettrainnumber() {
		return trainnumber;
		}
		void inputtraindetails(){
			cout<<"train number:";cin>>trainnumber;
			cout<<"train name:";cin>>trainname;
			cout<<"train source:";cin>>source;
			cout<<"train destination:";cin>>destination;
			cout<<"train time:";cin>>traintime;
			traincount++;
		}
		
		void displaytraindetaild(){
			cout<<"train number:"<<trainnumber<<"\ntrain name"<<trainname<<
			"\ntrain source"<<source<<"\ntrain destination"<<destination<<
			"\ntrain time"<<traintime<<endl;
		}
};
int train :: traincount = 0;

class railwaysystem{
	private:
		train trains[100];
		int totaltrains = 0;
		
	public:
		void addtrains(){
			if (totaltrains < 100){
				trains[totaltrains].inputtraindetails();
				totaltrains++;
			}else{
				cout<<"system is full!!!"<<endl;
			}
		}
		
		void displayalltrains(){
			if (totaltrains == 0){
				cout<<"no data available."<<endl;
			}else{
				for(int i=0; i<totaltrains; i++){
				cout<<"\ntrain"<< i + 1<< "details:"<< endl;
				trains[i].displaytraindetaild();
			    }
			}
		}
		
		void searchtrainbynumber(int number) {
		    int found = 0;
			for (int  i=0; i<totaltrains; i++){
				if (trains[i].gettrainnumber() == number){
					trains[i].displaytraindetaild();
					found = 1;
					break;
				}
			}
			if(!found){
				cout<<"train not found."<<endl;
			}
		}
};

int main(){
	railwaysystem rs;
	int choice, tnum;
	
	do{
		cout<<"\n----raileay reservation system menue ----"<<endl;
		cout<<"1. add new train record"<<endl;
		cout<<"2. display all train recourds"<<endl;
		cout<<"3. search train by number"<<endl;
		cout<<"4. exit"<<endl;
		cout<<"enter your choice:";
		cin>> choice;
		
		switch (choice){
			case 1:
				rs.addtrains();
				break;
			case 2:
				rs.displayalltrains();
				break;
			case 3:
				cout <<"enter train number to search:";
				cin>> tnum;
				rs.searchtrainbynumber(tnum);
				break;
			case 4:
				cout<<"exiting..."<<endl;
				break;
			default:
				cout<<"invalid choice!!"<<endl;
		}
	}while (choice != 4);
}
/*
----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:1
train number:101
train name:okha
train source:surat
train destination:mumbai
train time:10AM

----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:1
train number:102
train name:ook
train source:mumbai
train destination:surat
train time:11PM

----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:2

train1details:
train number:101
train nameokha
train sourcesurat
train destinationmumbai
train time10AM

train2details:
train number:102
train nameook
train sourcemumbai
train destinationsurat
train time11PM

----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:3
enter train number to search:102
train number:102
train nameook
train sourcemumbai
train destinationsurat
train time11PM

----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:3
enter train number to search:10
train not found.

----raileay reservation system menue ----
1. add new train record
2. display all train recourds
3. search train by number
4. exit
enter your choice:4
exiting...
*/