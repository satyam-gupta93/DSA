#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
    int solveRec(int indx,int buy,vector<int>& prices){
        if(indx >= prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[indx] + solveRec(indx+1,0,prices), solveRec(indx+1,1,prices));
        }else{
            profit = max(prices[indx] + solveRec(indx+2,1,prices), solveRec(indx+1,0,prices));
        }

        return profit;
        
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * 2)
   SC: O(n * 2)
*/
    int solveMemo(int indx,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(indx >= prices.size()){
            return 0;
        }

        if(dp[indx][buy]!=-1){
            return dp[indx][buy];
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[indx] + solveMemo(indx+1,0,prices,dp), solveMemo(indx+1,1,prices,dp));
        }else{
            profit = max(prices[indx] + solveMemo(indx+2,1,prices,dp), solveMemo(indx+1,0,prices,dp));
        }

        return dp[indx][buy] =  profit;
        
    }

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * 2)
   SC: O(n * 2)
*/
int maxProfitTab(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n+2,vector<int> (2,0));

        for(int i = n-1; i>=0; i--){
            for(int b = 0; b<2; b++){
                int profit = 0;
                if(b){
                    profit = max( -prices[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+2][1],dp[i+1][0]);
                }

                dp[i][b] = profit;
            }


        }

        return dp[0][1];
}

/* 
   4. SPACE OPTIMIZED (BEST)
   TC: O(n * 2)
   SC: O(1)
 */
int maxProfitSpaceOptimized(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n+2,vector<int> (2,0));

        vector<int> front2(2,0);
        vector<int> front(2,0);
       


        for(int i = n-1; i>=0; i--){
            vector<int> curr(2,0);
            for(int b = 0; b<2; b++){
                int profit = 0;
                if(b){
                    profit = max( -prices[i] + front[0], front[1]);
                }else{
                    profit = max(prices[i] + front2[1],front[0]);
                }

                curr[b] = profit;
            }

            front2 = front;
            front = curr;


        }

        return front[1];
}


int main() {

    vector<int> prices = {1, 2, 3, 0, 2};

    cout << "Recursion:"<< solveRec(0, 1, prices) << endl;

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout << "Memoization:"<< solveMemo(0, 1, prices, dp) << endl;

    cout << "Tabulation:"<< maxProfitTab(prices) << endl;

    cout << "Space Optimized:"<< maxProfitSpaceOptimized(prices) << endl;

    return 0;
}
