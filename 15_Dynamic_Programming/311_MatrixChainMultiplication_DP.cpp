#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n) recursion stack
*/
    int solveRec(int i,int j,vector<int> &arr){
        
        if( i == j){
            return 0;
        }
        
        int step = INT_MAX;
        for(int k = i; k<=j-1; k++){
            step = min(step,arr[i-1] * arr[k] * arr[j] + solveRec(i,k,arr) + solveRec(k+1,j,arr));
        }
        return step;
    }

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^3)
   SC: O(n^2) + recursion stack
*/
int solveMemo(int i, int j, vector<int>& arr,
              vector<vector<int>>& dp) {

        if( i == j){
            return 0;
        }
        
        if( dp[i][j] != -1){
            return dp[i][j];
        }
        
        int step = INT_MAX;
        for(int k = i; k<=j-1; k++){
            step = min(step,arr[i-1] * arr[k] * arr[j] + solveMemo(i,k,arr,dp) + solveMemo(k+1,j,arr,dp));
        }
        return dp[i][j] =  step;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n^3)
   SC: O(n^2)
*/
int matrixMultiplicationTab(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i = n-1; i>=1; i--){
            for(int j = i+1; j<=n-1;j++){
                int step = INT_MAX;
                for(int k = i; k<=j-1; k++){
                    step = min(step,arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = step;
            }
        }
        
    return dp[1][n-1];
}

int main() {

    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    cout << "Recursion:"<< solveRec(1, n - 1, arr) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization:"<< solveMemo(1, n - 1, arr, dp) << endl;

    cout << "Tabulation:"<< matrixMultiplicationTab(arr) << endl;

    return 0;
}
