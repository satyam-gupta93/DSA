#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter N:";
    cin>>n;

    // methpd - 1 
    // int ans=0;
    // int power=1;
    // while(n!=0){
       
    //    int bit = (n&1);
    //    ans = bit*power +  ans ; 
    //    power = power *10;
    //    n = n >> 1;
    // }
    // cout<<"In Binary:"<<ans;

    // method - 2 
    int ans = 0;
    int pow = 1;
    while(n!=0){
        int a = n%2;
        ans = a* pow + ans ;
        pow  = pow *10;
        // cout<<a<<" ";
        n = n /2;

    }
    cout<<ans;
}