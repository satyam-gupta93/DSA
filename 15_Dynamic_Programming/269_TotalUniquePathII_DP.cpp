#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION
   TC: Exponential
   SC: O(m+n)
 */
int solveRec(int i, int j, vector<vector<int>>& obsG) {

        if(i<0 || j<0){
            return 0;
        }
        if(obsG[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }

        
        int up = solveRec(i-1,j,obsG);
        int left = solveRec(i,j-1,obsG);

        return up + left;
}


/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(m*n)
   SC: O(m*n)
*/
int solveMemo(int i, int j, vector<vector<int>>& obsG,
              vector<vector<int>>& dp) {

        if(i<0 || j<0){
            return 0;
        }
        if(obsG[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up = solveMemo(i-1,j,obsG,dp);
        int left = solveMemo(i,j-1,obsG,dp);

        return dp[i][j] = up + left;
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(m*n)
   SC: O(m*n)
*/
int uniquePathsTab(vector<vector<int>>& obsG) {

        int n = obsG.size();
        int m = obsG[0].size();

        vector<vector<int>> dp(n,vector<int> (m,0));   

        if(obsG[0][0]==1){
            return 0;
        } 

        dp[0][0] = 1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    continue;
                }
                int down = 0;
                int right = 0;
                if(i>0 && obsG[i][j]==0){
                   down = dp[i-1][j];
                }
                if(j>0 && obsG[i][j]==0){
                    right = dp[i][j-1];
                }
                dp[i][j] = down + right;
            }
        } 

        return dp[n-1][m-1];  
}

/* 
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(m*n)
   SC: O(n)
*/
int uniquePathsSpaceOP(vector<vector<int>>& obsG) {

        int n = obsG.size();
        int m = obsG[0].size();

        vector<int> prev(m,0);


        if(obsG[0][0]==1){
            return 0;
        } 

        prev[0] = 1;
      

        for(int i = 0; i<n; i++){
            vector<int> curr(m,0);
            curr[0] = 1;
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    continue;
                }
                int down = 0;
                int right = 0;
                if(i>0 && obsG[i][j]==0){
                   down = prev[j];
                }
                if(j>0 && obsG[i][j]==0){
                    right = curr[j-1];
                }
                curr[j] = down + right;
            }

            prev = curr;
        } 

        return prev[m-1];  
}

int main() {

    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    cout << "Recursion:"<<solveRec(m - 1, n - 1, obstacleGrid) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization:"<< solveMemo(m - 1, n - 1, obstacleGrid, dp) << endl;

    cout << "Tabulation:"<< uniquePathsTab(obstacleGrid) << endl;

    cout << "Space Optimized:"<< uniquePathsSpaceOP(obstacleGrid) << endl;

    return 0;
}
