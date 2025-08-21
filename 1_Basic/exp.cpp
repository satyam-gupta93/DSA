#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter N:";
    cin>>n;

     while(n>1){
        n = n/2;
        cout<<n;
     }
     cout<<n;
}