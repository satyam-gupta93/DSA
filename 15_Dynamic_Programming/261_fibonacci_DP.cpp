#include<bits/stdc++.h>
using namespace std;

int fibo( vector<int> &dp,int n){

    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = fibo(dp,n-2) + fibo(dp,n-1);
}

int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;

    vector<int> dp(n+1,-1);

    int ans = fibo(dp,n);

    cout<<"Ans:"<<ans<<endl;

}