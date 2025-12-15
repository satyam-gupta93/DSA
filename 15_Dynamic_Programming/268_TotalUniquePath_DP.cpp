#include <bits/stdc++.h>
using namespace std;

/* 
   RECURSION
   TC: Exponential (O(2^(m+n)))
   SC: O(m+n)  (recursion stack)
 */
    int solveRec(int i,int j){

        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0){
            return 0;
        }

        int up = solveRec(i-1,j);
        int left = solveRec(i,j-1);

        return up + left;
    }

/* 
   MEMOIZATION (Top-Down DP)
   TC: O(m*n)
   SC: O(m*n) + O(m+n) recursion stack
*/
int solveMemo(int i, int j, vector<vector<int>> &dp) {
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = solveMemo(i-1,j,dp);
        int left = solveMemo(i,j-1,dp);

        return dp[i][j] = up + left;
}

/* 
   TABULATION (Bottom-Up DP)
   TC: O(m*n)
   SC: O(m*n)
 */
    int uniquePathsTab(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,0));

        dp[0][0] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j==0){
                    continue;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i>0){
                       up = dp[i-1][j];
                    }
                    if(j>0){
                      left = dp[i][j-1];
                    }
                    
                    

                    dp[i][j] = up + left;
                }

            }
        }

        return dp[m-1][n-1];
}

/*
   SPACE OPTIMIZATION
   TC: O(m*n)
   SC: O(n)
*/
    int uniquePathsSpaceOP(int m, int n) {
        
        vector<int> prev(n,0);

        prev[0] = 1;

        for(int i = 0; i<m; i++){
            vector<int> curr(n,0);
            curr[0] = 1;
            for(int j = 0; j<n; j++){
                if(i == 0 && j==0){
                    continue;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i>0){
                       up = prev[j];
                    }
                    if(j>0){
                      left = curr[j-1];
                    }
                    
                    curr[j] = up + left;
                    
                  
                }

            }
            prev = curr;
        }


        return prev[n-1];
}

int main() {
    int m = 3, n = 7;

    

    cout << "Recursion:"<< solveRec(m-1, n-1) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization:"<< solveMemo(m - 1, n - 1, dp) << endl;

    cout << "Tabulation:"<< uniquePathsTab(m, n) << endl;

    cout << "Space Optimized:"<< uniquePathsSpaceOP(m, n) << endl;

    return 0;
}
