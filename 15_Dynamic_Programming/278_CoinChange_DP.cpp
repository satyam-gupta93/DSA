#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(amount) recursion stack
*/
int solveRec(int indx, vector<int>& coins, int amount) {

        if(indx==0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }else{
                return 1e9;
            }
        }


        int take = 1e9;
        if( amount >= coins[indx] ){
            take = 1 + solveRec(indx,coins,amount-coins[indx]);
        }
        int skip = solveRec(indx-1,coins,amount);

        return min(take,skip);
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * amount)
   SC: O(n * amount)
*/
int solveMemo(int indx, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        if(indx==0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }else{
                return 1e9;
            }
        }

        if(dp[indx][amount]!=-1){
            return dp[indx][amount];
        }

        int take = 1e9;
        if( amount >= coins[indx] ){
            take = 1 + solveMemo(indx,coins,amount-coins[indx],dp);
        }
        int skip = solveMemo(indx-1,coins,amount,dp);

        return dp[indx][amount] =  min(take,skip);
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * amount)
   SC: O(n * amount)
 */
int coinChangeTab(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));


       for(int a = 0; a<=amount; a++){
            if(a%coins[0] == 0){
                dp[0][a] = a/coins[0];
            }
       }

       for(int i = 1; i<n; i++){
            for(int a = 0; a<=amount; a++){
                int take = 1e9;
                if(coins[i] <=a){
                    take = 1 + dp[i][a-coins[i]];
                }
                int skip = dp[i-1][a];

                dp[i][a] = min(take,skip);
            }
       }

       int ans = dp[n-1][amount];

       if(ans == 1e9){
         return -1;
       }else{
            return ans;
       }
}

/*
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(n * amount)
   SC: O(amount)
*/
int coinChangeSpaceOP(vector<int>& coins, int amount) {

        int n = coins.size();
     
        vector<int> prev(amount+1,1e9);

       for(int a = 0; a<=amount; a++){
            if(a%coins[0] == 0){
                prev[a] = a/coins[0];
            }
       }

       for(int i = 1; i<n; i++){
            vector<int> curr(amount+1,1e9);
            for(int a = 0; a<=amount; a++){
                int take = 1e9;
                if(coins[i] <=a){
                    take = 1 +curr[a-coins[i]];
                }
                int skip = prev[a];

               curr[a] = min(take,skip);
            }
            prev = curr;
       }

       int ans = prev[amount];

       if(ans == 1e9){
         return -1;
       }else{
            return ans;
       }
}


int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int n = coins.size();

    int ansRec = solveRec(n - 1, coins, amount);
    cout << "Recursion:"<< ((ansRec >= 1e9) ? -1 : ansRec) << endl;

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ansMemo = solveMemo(n - 1, coins, amount, dp);
    cout << "Memoization:"<< ((ansMemo >= 1e9) ? -1 : ansMemo) << endl;

    cout << "Tabulation:"<< coinChangeTab(coins, amount) << endl;

    cout << "Space Optimized:"<< coinChangeSpaceOP(coins, amount) << endl;

    return 0;
}
