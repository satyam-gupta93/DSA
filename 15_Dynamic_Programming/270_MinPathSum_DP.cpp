#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION
   TC: Exponential
   SC: O(m+n)
*/
int solveRec(int i, int j, vector<vector<int>>& grid) {

        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        int up = solveRec(i-1,j,grid);
        int right = solveRec(i,j-1,grid);

        return grid[i][j] + min(up,right);
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(m*n)
   SC: O(m*n)
*/
int solveMemo(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = solveMemo(i-1,j,grid,dp);
        int right = solveMemo(i,j-1,grid,dp);

        return dp[i][j] =  grid[i][j] + min(up,right);
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(m*n)
   SC: O(m*n)
*/
int minPathSumTab(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));

        dp[0][0] = grid[0][0];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    continue;
                }
                int up = INT_MAX;
                int down = INT_MAX;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    down = dp[i][j-1];
                } 

                dp[i][j] = grid[i][j] + min(up,down);
            }
        }

        return dp[n-1][m-1];
}

/*
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(m*n)
   SC: O(m)
*/
int minPathSumSpaceOP(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
       
        vector<int> prev(m,0);
        
        prev[0] = grid[0][0];

        for(int i = 0; i<n; i++){
            vector<int> curr(m,0);
            curr[0] = grid[0][0];
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    continue;
                }
                int up = INT_MAX;
                int down = INT_MAX;
                if(i>0){
                    up = prev[j];
                }
                if(j>0){
                    down = curr[j-1];
                } 

                curr[j] = grid[i][j] + min(up,down);
            }
            prev = curr;
        }

        return prev[m-1];
}


int main() {

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    cout << "Recursion:"<< solveRec(n - 1, m - 1, grid) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization:"<< solveMemo(n - 1, m - 1, grid, dp) << endl;

    cout << "Tabulation:"<< minPathSumTab(grid) << endl;

    cout << "Space Optimized:"<< minPathSumSpaceOP(grid) << endl;

    return 0;
}
