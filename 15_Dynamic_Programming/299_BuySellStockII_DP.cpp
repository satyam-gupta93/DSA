#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
int solveRec(int indx, int buy, vector<int>& prices) {

        if(indx == prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[indx] + solveRec(indx+1,0,prices), solveRec(indx+1,1,prices));
        }else{
            profit = max(prices[indx] + solveRec(indx+1,1,prices), solveRec(indx+1,0,prices));
        }

        return profit;
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * 2)
   SC: O(n * 2) + recursion stack
*/
int solveMemo(int indx, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

        if(indx == prices.size()){
            return 0;
        }

        if(dp[indx][buy]!=-1){
            return dp[indx][buy];
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[indx] + solveMemo(indx+1,0,prices,dp), solveMemo(indx+1,1,prices,dp));
        }else{
            profit = max(prices[indx] + solveMemo(indx+1,1,prices,dp), solveMemo(indx+1,0,prices,dp));
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
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int indx = n-1; indx>=0; indx--){
            for(int buy = 0;buy<=1; buy++){
                    int profit = 0;
                if(buy){
                    profit = max(-prices[indx] + dp[indx+1][0], dp[indx+1][1]);
                }else{
                    profit = max(prices[indx] +dp[indx+1][1], dp[indx+1][0]);
                }

                dp[indx][buy] =  profit;
            }
        }


        return dp[0][1];
}

/*
   4. SPACE OPTIMIZED (BEST)
   TC: O(n * 2)
   SC: O(2)
*/
int maxProfitSpaceOptimized(vector<int>& prices) {

        int n = prices.size();
    
        vector<int> front(2,0);

        for(int indx = n-1; indx>=0; indx--){
            vector<int> curr(2,0);
            for(int buy = 0;buy<=1; buy++){
                    int profit = 0;
                if(buy){
                    profit = max(-prices[indx] + front[0], front[1]);
                }else{
                    profit = max(prices[indx] +front[1], front[0]);
                }

               curr[buy] =  profit;
            }
            front = curr;
        }


        return front[1];
}


int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();

    cout << "Recursion:"<< solveRec(0, 1, prices) << endl;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << "Memoization:"<< solveMemo(0, 1, prices, dp) << endl;

    cout << "Tabulation:"<< maxProfitTab(prices) << endl;

    cout << "Space Optimized:"<< maxProfitSpaceOptimized(prices) << endl;

    return 0;
}
