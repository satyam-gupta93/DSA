#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n) recursion stack
*/
    int solveRec(int i,int j,vector<int>& cuts){
        if(i>j){
            return 0;
        }
        int mini = INT_MAX;

        for(int k = i;k<=j;k++){
            int cost = (cuts[j+1] - cuts[i-1]) + solveRec(i,k-1,cuts) + solveRec(k+1,j,cuts);
            mini = min(mini,cost);
        }

        return mini;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(m^3)
   SC: O(m^2) + recursion stack
   where m = number of cuts
*/
    int solveMemo(int i,int j,vector<int>& cuts, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = INT_MAX;

        for(int k = i;k<=j;k++){
            int cost = (cuts[j+1] - cuts[i-1]) + solveMemo(i,k-1,cuts,dp) + solveMemo(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }

        return dp[i][j] =  mini;
    }

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(m^3)
   SC: O(m^2)
*/
int minCostTab(int n, vector<int>& cuts) {

        cuts.push_back(n);
        cuts.push_back(0);

        int noCut = cuts.size();

        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(noCut+2,vector<int>(noCut+2,0));

        for(int i = noCut - 2; i>=1; i--){
            for(int j = i; j<=noCut-2; j++){
                int mini = INT_MAX;
                for(int k = i;k<=j;k++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return  dp[1][noCut-2];
}


int main() {

    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    vector<int> cuts1 = cuts;
    cuts1.push_back(0);
    cuts1.push_back(n);
    sort(cuts1.begin(), cuts1.end());

    int m = cuts1.size();

    cout << "Recursion:"<< solveRec(1, m - 2, cuts1) << endl;

    vector<vector<int>> dp(m, vector<int>(m, -1));
    cout << "Memoization:"<< solveMemo(1, m - 2, cuts1, dp) << endl;

    cout << "Tabulation:"<< minCostTab(n, cuts) << endl;

    return 0;
}
