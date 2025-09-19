#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<"Enter n:";
	cin>>n;
	
	// int i= 1;
	// while(i<=n){
	// 	cout<<i<<" ";
	// 	i=i+1;
		
	// }


	// int sum = 0;
	// int a=0;
	// int i=1;
	// while(i<n){
	// 	if(n%i==0){
	// 		cout<<"Number is prime";
	// 		a=1;
	// 		break;
	// 	}
		
	// 	i = i + 1 ;

	// }
	// if(a==0){
	// 	cout<<"Number is odd";
	// }
	// cout<<"Sum:"<<sum;

	// 
	

	// 1 2 3 
	// 4 5 6 
	// 7 8 9

	// int i=0;
	// int a=0;
	// while(i<n){
	// 	int j=0;
	// 	while(j<n){
	// 		cout<<a+1<<" ";
	// 		a++;
	// 		j++;
	// }
	// cout<<endl;
	// i++;
	// }	


	// *
	// **
	// ***
	// ****

	// int i=0;
	// while(i<n){
	// 	int j=0;
	// 	while(j<i+1){
	// 		cout<<i+1<<" ";
	// 		j++;

	// 	}
	// 	cout<<endl;
	// 	i++;
	// }


	// 1
	// 2 3
	// 3 4 5
	// 4 5 6 7
	// int i=0;
	// while(i<n){
	// 	int j=0;
	// 	while(j<i+1){
	// 		cout<<(2*i)-1<<" ";
	// 		j++;

	// 	}
	// 	cout<<endl;
	// 	i++;


	// }

	
	// int i=0;
	// while(i<n){
	// 	int j=0;
	// 	while(j<i+1){
	// 		cout<<(i+1)-j<<" ";
	// 		j++;

	// 	};
	// 	cout<<endl;
	// 	i++;
	// }


	
	int i=0;
	int a=0;
	while(i<n){
		int j=0;
		while(j<i+1){
			cout<<char(65+j)<<" ";
		
			j++;

		};
		cout<<endl;
		i++;
	}
	
	
	return 0;
}
