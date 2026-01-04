#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
int solveRec(int indx, int buy, int cap, vector<int>& prices) {

        if(cap == 0){
            return 0;
        }
        if(indx == prices.size()){
            return 0;
        }
        int profit = 0;
        if(buy){
            profit = max( -prices[indx] + solveRec(indx+1,0,cap,prices), solveRec(indx+1,1,cap,prices) );
        }else{
            profit = max( prices[indx] + solveRec(indx+1,1,cap-1,prices), solveRec(indx+1,0,cap,prices) );
        }

        return profit;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * 2 * k)
   SC: O(n * 2 * k)
*/
int solveMemo(int indx, int buy, int cap,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if(cap == 0){
            return 0;
        }
        if(indx == prices.size()){
            return 0;
        }
        if(dp[indx][buy][cap]!=-1){
            return dp[indx][buy][cap];
        }
        int profit = 0;
        if(buy){
            profit = max( -prices[indx] + solveMemo(indx+1,0,cap,prices,dp), solveMemo(indx+1,1,cap,prices,dp) );
        }else{
            profit = max( prices[indx] + solveMemo(indx+1,1,cap-1,prices,dp), solveMemo(indx+1,0,cap,prices,dp) );
        }

        return dp[indx][buy][cap] = profit;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * 2 * k)
   SC: O(n * 2 * k)
*/
int maxProfitTab(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,0)));

        for(int i = n-1; i>=0; i--){
            for(int b = 0; b<2; b++){
                for(int c = 1; c<=k; c++){
                    int profit = 0;
                    if(b){
                        profit = max( -prices[i] + dp[i+1][0][c] , dp[i+1][1][c] );
                    }else{
                        profit = max( prices[i] + dp[i+1][1][c-1] , dp[i+1][0][c] );
                    }

                    dp[i][b][c] = profit;
                }
            }
        }
        return dp[0][1][k];
}

/* 
   4. SPACE OPTIMIZED (BEST)
   TC: O(n * 2 * k)
   SC: O(2 * k)
*/
int maxProfitSpaceOptimized(int k, vector<int>& prices) {

        int n = prices.size();

      
        vector<vector<int>> front(2,vector<int>(k+1,0));
        for(int i = n-1; i>=0; i--){
            vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int b = 0; b<2; b++){
                for(int c = 1; c<=k; c++){
                    int profit = 0;
                    if(b){
                        profit = max( -prices[i] + front[0][c] , front[1][c] );
                    }else{
                        profit = max( prices[i] + front[1][c-1] , front[0][c] );
                    }

                    curr[b][c] = profit;
                }
            }
            front = curr;
        }
        return front[1][k];
}


int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    cout << "Recursion: "<< solveRec(0, 1, k, prices) << endl;

    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k + 1, -1))
    );

    cout << "Memoization:"<< solveMemo(0, 1, k, prices, dp) << endl;

    cout << "Tabulation:"<< maxProfitTab(k, prices) << endl;

    cout << "Space Optimized:"<< maxProfitSpaceOptimized(k, prices) << endl;

    return 0;
}
