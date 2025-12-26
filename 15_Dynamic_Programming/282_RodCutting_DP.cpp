#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
int solveRec(int indx, int len, vector<int>& price) {

        if(indx == 0){

            return len*price[0];

        }
        int take = INT_MIN;
        if( indx + 1 <= len  ){
            take = price[indx] + solveRec(indx,len-(indx + 1),price);
        }
        
        int skip = solveRec(indx-1,len,price);
        
        return max(take,skip);
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * n)
   SC: O(n * n)
*/
int solveMemo(int indx, int len, vector<int>& price,
              vector<vector<int>>& dp) {

        if(indx == 0){
           
            return len*price[0];   
        }
        if(dp[indx][len] != -1){
            return dp[indx][len];
        }
        
        int take = INT_MIN;
        if( indx + 1 <= len  ){
            take = price[indx] + solveMemo(indx,len-(indx + 1),price,dp);
        }
        
        int skip = solveMemo(indx-1,len,price,dp);
        
        return dp[indx][len] =  max(take,skip);
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * n)
   SC: O(n * n)
*/
int cutRodTab(vector<int>& price) {

        int n = price.size();
        vector<vector<int>> dp(n,vector<int> (n+1,0));
        for(int l = 0; l<=n; l++){
            dp[0][l] = l*price[0];
        }
        
        for(int i = 1; i<n; i++){
            for(int l = 0; l<=n; l++){
                
                int take = INT_MIN;
                if( i+1 <= l ){
                    take = price[i] +  dp[i][l - (i+1)];
                }
                
                int skip = dp[i-1][l];
                
                dp[i][l] = max(take,skip);
            }
        }
        return dp[n-1][n];
}

/*
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * n)
   SC: O(n)
*/
int cutRod(vector<int>& price) {

        int n = price.size();
      
        vector<int> prev(n+1,0);
        for(int l = 0; l<=n; l++){
           prev[l] = l*price[0];
        }
        
        for(int i = 1; i<n; i++){
            vector<int> curr(n+1,0);
            for(int l = 0; l<=n; l++){
                
                int take = INT_MIN;
                if( i+1 <= l ){
                    take = price[i] +  curr[l - (i+1)];
                }
                
                int skip = prev[l];
                
               curr[l] = max(take,skip);
            }
            prev = curr;
        }
        return prev[n];
}


int main() {

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();

    cout << "Recursion:"<< solveRec(n - 1, n, price) << endl;

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, n, price, dp) << endl;

    cout << "Tabulation:"<< cutRodTab(price) << endl;

    cout << "Space Optimized:"<< cutRod(price) << endl;

    return 0;
}
