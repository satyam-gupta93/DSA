#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(amount)
*/
int solveRec(int indx, int amount, vector<int>& coins) {

        if(indx == 0){
            if(amount%coins[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }

        int take = 0;
        if( coins[indx] <= amount ){
            take = solveRec(indx,amount-coins[indx],coins);
        }
        int skip = solveRec(indx-1,amount,coins);

        return take + skip;
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * amount)
   SC: O(n * amount)
*/
int solveMemo(int indx, int amount, vector<int>& coins,
              vector<vector<int>>& dp) {

        if(indx == 0){
            if(amount%coins[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[indx][amount] != -1){
            return dp[indx][amount];
        }

        int take = 0;
        if( coins[indx] <= amount ){
            take = solveMemo(indx,amount-coins[indx],coins,dp);
        }
        int skip = solveMemo(indx-1,amount,coins,dp);

        return dp[indx][amount] =  take + skip;
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * amount)
   SC: O(n * amount)
*/
int changeTab(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));

        for(int a = 0; a<=amount; a++){
            if(a%coins[0] == 0){
                dp[0][a] = 1;
            }
        }

        for(int i = 1; i<n; i++){
            for(int a = 0; a<=amount; a++){
                int take = 0;
                if( coins[i] <= a ){
                    take = dp[i][a-coins[i]];
                }
                int skip = dp[i-1][a];

                dp[i][a] = take + skip;
            }
        }

        return dp[n-1][amount];
}

/* 
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * amount)
   SC: O(amount)
 */
int change(int amount, vector<int>& coins) {

        int n = coins.size();
     
        vector<long long> prev(amount+1,0);
        for(int a = 0; a<=amount; a++){
            if(a%coins[0] == 0){
               prev[a] = 1;
            }
        }

        for(int i = 1; i<n; i++){
            vector<long long > curr(amount+1,0);
            for(int a = 0; a<=amount; a++){
                long long  take = 0;
                if( coins[i] <= a ){
                    take = curr[a-coins[i]];
                }
                long long skip = prev[a];

               curr[a] = take + skip;
            }
            prev = curr;
        }

        return (int)prev[amount];
}


int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();

    cout << "Recursion:"<< solveRec(n - 1, amount, coins) << endl;

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, amount, coins, dp) << endl;

    cout << "Tabulation:"<< changeTab(amount, coins) << endl;

    cout << "Space Optimized:"<< change(amount, coins) << endl;

    return 0;
}
