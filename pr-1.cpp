#include<iostream>
using namespace std;

class timeconverter{
	public:
	int h, m, s;
	int ts;
	
	void convtohms(){
		cout<<"enter total seconds:";
		cin>>ts;
		
		int h = ts / 3600;
		int m = (ts % 3600) / 60;
		int s = ts % 60;
		
		cout<<"HH:MM:SS=>"<<h<<":"<<m<<":"<<s<<endl;
	}
	
	void hmstoconv(){
		cout<<"\nenter hours:";
		cin>>h;
		cout<<"enter minutes:";
		cin>>m;
		cout<<"enter seconds:";
		cin>>s;
		
		int ts = (h * 3600) + (m * 60) + s;
		
		cout<<"total seconds:"<<ts; 
	}
};
 int main()
 {
 	timeconverter x;
 	int c;
 	
 	cout<<"1.  total seconds convert to HMS"<<endl;
 	cout<<"2.  HMS convert to total seconds"<<endl;
 	cout<<"choose:";
 	cin>>c;
 	if(c == 1){
 	x.convtohms();
    }else{
 	x.hmstoconv();
    }
 }
 /*
1.  total seconds convert to HMS
2.  HMS convert to total seconds
choose:1
enter total seconds:49000
HH:MM:SS=>13:36:40

1.  total seconds convert to HMS
2.  HMS convert to total seconds
choose:2

enter hours:12
enter minutes:2
enter seconds:13
total seconds:43333
 */