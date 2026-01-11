#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(k^n)  (Exponential)
   SC: O(n)    (Recursion stack)
*/
int solveRec(int i,vector<int>& arr,int k){
        if( i == arr.size()){
            return 0;
        }
        int maxi = INT_MIN;
           int curMax = 0;
        for(int j = i;j < arr.size() && j < i + k;j++){
            curMax = max(curMax,arr[j]);
            int cost =  curMax*(j-i+1) + solveRec(j+1,arr,k);
            maxi = max(maxi,cost);
        }
        

        return maxi;
        
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * k)
   SC: O(n)
*/
    int solveMemo(int i,vector<int>& arr,int k,vector<int> &dp){
        if( i == arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi = INT_MIN;
         int curMax = 0;
        for(int j = i;j < arr.size() && j < i + k;j++){
            curMax = max(curMax,arr[j]);
            int cost =  curMax*(j-i+1) + solveMemo(j+1,arr,k,dp);
            maxi = max(maxi,cost);
        }
        

        return dp[i] =  maxi;
        
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * k)
   SC: O(n)
*/
int maxSumAfterPartitioningTab(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i = n-1; i>=0;i--){
            int maxi = INT_MIN;
            int curMax = 0;
            for(int j = i;j < arr.size() && j < i + k;j++){
                curMax = max(curMax,arr[j]);
                int cost =  curMax*(j-i+1) + dp[j+1];
                maxi = max(maxi,cost);
            }
            dp[i] = maxi;
        }
        return dp[0];
}

int main() {

    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Recursion:"<< solveRec(0, arr, k) << endl;

    vector<int> dp(arr.size(), -1);
    cout << "Memoization:"<< solveMemo(0, arr, k, dp) << endl;

    cout << "Tabulation:"<< maxSumAfterPartitioningTab(arr, k) << endl;

    return 0;
}
