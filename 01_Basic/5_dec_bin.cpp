#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter N:";
    cin>>n;

    // int ans = 0;
    // int i = 0;
    // while(n!=0){
    //     int a = n%10;
    //     if(a==0){
    //          n = n /10;
    //         i++;
    //         continue;
    //     }
    //     n = n /10;
    //     ans = ans  + pow(2,i)*a;
    //     i++;
    // }
    int ans=0;
    int power = 1;
    int sum = 0;
    int i = 0;
    while(n!=0){
        int bit = (n&1);
        int newbit = (bit^1);
        if(newbit==0){
            n = n>>1;
            i++;
            continue;
        }
        sum = sum + newbit*pow(2,i);
        i++;
        cout<<newbit;
        ans =  ans + (newbit * power);
        n = n>>1;
        power++;
        
    }
    cout<<ans<<endl<<sum;
}