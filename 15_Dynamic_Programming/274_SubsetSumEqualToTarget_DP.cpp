#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(2^n)
   SC: O(n)
*/
bool solveRec(vector<int>& arr, int indx, int sum) {

        if(sum == 0){
            return true;
        }
        if(indx == 0){
            return sum==arr[0];
        }
        bool take = false;
        if(arr[indx] <= sum ){
          take = solveRec(arr,indx-1,sum-arr[indx]);
        }
        
        bool skip = solveRec(arr,indx-1,sum);
        
        
        return take || skip;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * sum)
   SC: O(n * sum)
*/
bool solveMemo(vector<int>& arr, int indx, int sum,
               vector<vector<int>>& dp) {

        if(sum == 0){
            return true;
        }
        if(indx == 0){
            return sum==arr[0];
        }
        if(dp[indx][sum] != -1 ){
            return dp[indx][sum];
        }
        bool take = false;
        if(arr[indx] <= sum ){
          take = solveMemo(arr,indx-1,sum-arr[indx],dp);
        }
        
        bool skip = solveMemo(arr,indx-1,sum,dp);
        
        
        return dp[indx][sum] =  take || skip;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * sum)
   SC: O(n * sum)
*/
bool isSubsetSumTab(vector<int>& arr, int sum) {

        int n = arr.size();
        
        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
        
        for(int i = 0; i<n; i++){
            dp[i][0]  = true; 
        }
        
        if(arr[0]<=sum){
            dp[0][arr[0]] = true;
        }
        
        
        for(int i = 1; i<n;i++){
            for( int s = 1; s<=sum; s++){
                bool take = false;
                if(arr[i] <= s ){
                    take = dp[i-1][s-arr[i]];
                }
                bool skip = dp[i-1][s];
                
                dp[i][s] = take || skip;
            }
        }
        
        return dp[n-1][sum];
}

/* 
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(n * sum)
   SC: O(sum)
*/
bool isSubsetSumSpaceOP(vector<int>& arr, int sum) {

        int n = arr.size();
        

        vector<bool> prev(sum+1,false);
        

        prev[0]  = true; 

        
        if(arr[0]<=sum){
            prev[arr[0]] = true;
        }
        
        
        for(int i = 1; i<n;i++){
            
            vector<bool> curr(sum+1,false);
            curr[0] = true;
            for( int s = 1; s<=sum; s++){
                
                bool take = false;
                if(arr[i] <= s ){
                    take = prev[s-arr[i]];
                }
                bool skip = prev[s];
                
                curr[s] = take || skip;
            }
            prev = curr;
        }
        
        return prev[sum];
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = arr.size();

    cout << "Recursion:"<< solveRec(arr, n - 1, sum) << endl;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << "Memoization:"<< solveMemo(arr, n - 1, sum, dp) << endl;

    cout << "Tabulation:"<< isSubsetSumTab(arr, sum) << endl;

    cout << "Space Optimized:"<< isSubsetSumSpaceOP(arr, sum) << endl;

    return 0;
}
