#include<bits/stdc++.h>
using namespace std;

// Memoization 
int fibo( vector<int> &dp,int n){

    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = fibo(dp,n-2) + fibo(dp,n-1);
}

// Tabulation
int fiboTabulation(int n){

    vector<int> dp(n+1,-1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;

    vector<int> dp(n+1,-1);

    int ansMemo = fibo(dp,n);
    int ansTabul = fiboTabulation(n);

    cout<<"Ans Memoization:"<<ansMemo<<endl;
    cout<<"Ans Tabulation:"<<ansTabul<<endl;

}