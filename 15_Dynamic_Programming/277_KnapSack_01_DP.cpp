#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(2^n)
   SC: O(n)
 */
int solveRec(int indx, int w, vector<int>& val, vector<int>& wt) {

        if(indx==0){
            if(wt[indx]<=w){
                return val[indx];
            }else{
                return 0;
            }
        }
        
        int take = INT_MIN;
        if(wt[indx]<=w){
            take = val[indx]+ solveRec(indx-1,w-wt[indx],val,wt);
        }
        int skip = solveRec(indx-1,w,val,wt);
        
        return max(take,skip);
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * W)
   SC: O(n * W)
*/
int solveMemo(int indx, int w, vector<int>& val, vector<int>& wt,
              vector<vector<int>>& dp) {

        if(indx==0){
            if(wt[indx]<=w){
                return val[indx];
            }else{
                return 0;
            }
        }
        
        if(dp[indx][w]!=-1){
            return dp[indx][w];
        }
        
        int take = INT_MIN;
        if(wt[indx]<=w){
            take = val[indx]+ solveMemo(indx-1,w-wt[indx],val,wt,dp);
        }
        int skip = solveMemo(indx-1,w,val,wt,dp);
        
        return dp[indx][w] = max(take,skip);
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * W)
   SC: O(n * W)
*/
int knapsackTab(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));

        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }
        for(int i = 1; i<n; i++){
            for(int w = 0; w<=W; w++){
                int take = INT_MIN;
                if(wt[i]<=w){
                    take = val[i]+ dp[i-1][w-wt[i]];
                }
                int skip = dp[i-1][w];
                
                dp[i][w] = max(take,skip);
            }
        }
        return dp[n-1][W];
}

/*
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(n * W)
   SC: O(W)
*/
int knapsackSpaceOP(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
 
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }
        for(int i = 1; i<n; i++){
            for(int w = 0; w<=W; w++){
                int take = INT_MIN;
                if(wt[i]<=w){
                    take = val[i]+ dp[i-1][w-wt[i]];
                }
                int skip = dp[i-1][w];
                
                dp[i][w] = max(take,skip);
            }
        }
        return dp[n-1][W];
}

int main() {

    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;
    int n = val.size();

    cout << "Recursion:"<< solveRec(n - 1, W, val, wt) << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, W, val, wt, dp) << endl;

    cout << "Tabulation:"<< knapsackTab(W, val, wt) << endl;

    cout << "Space Optimized:"<< knapsackSpaceOP(W, val, wt) << endl;

    return 0;
}
