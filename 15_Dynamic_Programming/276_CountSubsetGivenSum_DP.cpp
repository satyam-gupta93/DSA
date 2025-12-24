#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(2^n)
   SC: O(n)
*/
int solveRec(int indx, vector<int>& arr, int target) {

        if(indx == 0){
            if(arr[0] == 0 &&target == 0){
                return 2; // {0} ,{}
            }
            if(arr[0]== target || target==0){
                return 1;
            }
            
            return 0;
        }
        int take = 0;
        if( arr[indx]<=target ){
            take =  solveRec(indx-1,arr,target-arr[indx]);
        }
        int skip = solveRec(indx-1,arr,target);
        
        return take + skip;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * target)
   SC: O(n * target)
*/
int solveMemo(int indx, vector<int>& arr, int target,
              vector<vector<int>>& dp) {

        if(indx == 0){
            if(arr[0] == 0 &&target == 0){
                return 2; // {0} ,{}
            }
            if(arr[0]== target || target==0){
                return 1;
            }
            
            return 0;
        }
        if(dp[indx][target]!=-1){
            return dp[indx][target];
        }
        int take = 0;
        if( arr[indx]<=target ){
            take =  solveMemo(indx-1,arr,target-arr[indx],dp);
        }
        int skip = solveMemo(indx-1,arr,target,dp);
        
        return dp[indx][target]=  take + skip;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * target)
   SC: O(n * target)
*/
int perfectSumTab(vector<int>& arr, int target) {

        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        if(arr[0]==0){
            dp[0][0] = 2;
        }else{
           
                dp[0][0] = 1;
     
            if(arr[0]<=target){
                dp[0][arr[0]] = 1;
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int s = 0; s<=target; s++){
                int take = 0;
                if( arr[i] <=s ){
                    take = dp[i-1][s-arr[i]];
                }
                
                int skip = dp[i-1][s];
                
                dp[i][s] = take + skip;
            }
        }
        return dp[n-1][target];
}



int main() {

    vector<int> arr = {0, 0, 1};
    int target = 1;
    int n = arr.size();

    cout << "Recursion:"<< solveRec(n - 1, arr, target) << endl;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, arr, target, dp) << endl;

    cout << "Tabulation:"<< perfectSumTab(arr, target) << endl;

  
    return 0;
}
