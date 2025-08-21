#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;
    // int sum = 0 ;

    // for(int i=1; i<=n ; i++){
    //     sum = sum + i;
    //     // cout<<i<<" ";
    // }
    // cout<<"Sum:"<<sum;


    // fibbo series
    // int a = 0;
    // int b= 1;

    // for (int i=1; i<=n ;i++){
    //     int  next = (a+b) ; 
    //     cout<<next<<" ";
    //     a = b;
    //     b = next;
    

    // }

    // prime 
    int a= 0;
    for(int i = 2 ; i<n ; i++){
        if(n%i==0){
            cout<<"Not prime!";
            a = 1;
            break;
        }
    }
    if(a==0){
        cout<<"Prime";
    }
}