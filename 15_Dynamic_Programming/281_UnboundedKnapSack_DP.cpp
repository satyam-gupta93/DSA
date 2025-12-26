#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(capacity)
 */
int solveRec(int indx, int capacity,
             vector<int>& val, vector<int>& wt) {

        if(indx == 0){
            if(capacity - wt[indx] >= 0){
                return (capacity/wt[indx])*val[indx];
            }else{
                return 0;
            }
        }
        
        int take = INT_MIN;
        if( wt[indx]<=capacity ){
            take = val[indx] + solveRec(indx,capacity-wt[indx],val,wt);
        }
        
        int skip = solveRec(indx-1,capacity,val,wt);
        
        return max(take,skip);
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * capacity)
   SC: O(n * capacity)
*/
int solveMemo(int indx, int capacity,
              vector<int>& val, vector<int>& wt,
              vector<vector<int>>& dp) {

        if(indx == 0){
            if(capacity - wt[indx] >= 0){
                return (capacity/wt[indx])*val[indx];
            }else{
                return 0;
            }
        }
        
        if(dp[indx][capacity]!=-1){
            return dp[indx][capacity];
        }
        
        int take = INT_MIN;
        if( wt[indx]<=capacity ){
            take = val[indx] + solveMemo(indx,capacity-wt[indx],val,wt,dp);
        }
        
        int skip = solveMemo(indx-1,capacity,val,wt,dp);
        
        return dp[indx][capacity] = max(take,skip);
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * capacity)
   SC: O(n * capacity)
*/
int knapSackTab(vector<int>& val, vector<int>& wt, int capacity) {

        int n = wt.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,0));
        
        for(int w = 0; w<=capacity; w++){
            dp[0][w] = (w/wt[0])*val[0];
        }
        
        for(int i = 1; i<n; i++){
            for(int w = 0; w<=capacity; w++){
                
                int take = INT_MIN;
                if( wt[i]<=w ){
                    take = val[i] + dp[i][w-wt[i]];
                }
                
                int skip = dp[i-1][w];
                
                dp[i][w] = max(take,skip);
            }
        }
        return dp[n-1][capacity];
}

/* 
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * capacity)
   SC: O(capacity)
*/
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = wt.size();
      
        vector<int> prev(capacity+1,0);
        for(int w = 0; w<=capacity; w++){
            prev[w] = (w/wt[0])*val[0];
        }
        
        for(int i = 1; i<n; i++){
            vector<int> curr(capacity+1,0);
            for(int w = 0; w<=capacity; w++){
                
                int take = INT_MIN;
                if( wt[i]<=w ){
                    take = val[i] + curr[w-wt[i]];
                }
                
                int skip = prev[w];
                
                curr[w] = max(take,skip);
            }
            prev = curr;
        }
        return prev[capacity];
}
int main() {

    vector<int> val = {10, 40, 50, 70};
    vector<int> wt  = {1, 3, 4, 5};
    int capacity = 8;
    int n = wt.size();

    cout << "Recursion:"<< solveRec(n - 1, capacity, val, wt) << endl;

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, capacity, val, wt, dp) << endl;

    cout << "Tabulation:"<< knapSackTab(val, wt, capacity) << endl;

    cout << "Space Optimized:"<< knapSack(val, wt, capacity) << endl;

    return 0;
}
