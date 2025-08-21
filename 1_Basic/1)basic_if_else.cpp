#include<iostream>
using namespace std;

int main(){
	
//	int n;
//	cout<<"Enter N:";
//	cin>>n;
//	
//	if(n>0){
//		cout<<n<<" is postive";
//		
//	}else if (n<0){
//		cout<<n<<" is negative";
//	}else{
//		cout<<n<<" is zero";
//	}


//	int a = 24;
//	
//	if(a>20){
//		cout<<"love";
//	}else if(a==24){
//		cout<<"Lovely";
//	}else{
//		cout<<"Babbar";
//	}
//	cout<<a;
//	


	char ch;
	cout<<"Enter char:";
	cin>>ch;
	if(ch>='a' && ch<='z'){
		cout<<"LowerCase";
	}else if(ch>'A' && ch<'Z'){
		cout<<"Upper";
	}else if(ch>='0' && ch<='9'){
		cout<<"Numeric";
	}else{
		cout<<"Enter valid input";
	}
	
	
	
}
