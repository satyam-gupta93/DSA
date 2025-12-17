#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(3^n)
   SC: O(n)
 */
int solveRec(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if( j<0 || j>=n || i<0 ){
            return INT_MAX;
        }

        if(i==0){
            return matrix[i][j];
        }

        int st = solveRec(i-1,j,matrix);
        int ld = solveRec(i-1,j-1,matrix);
        int rd = solveRec(i-1,j+1,matrix);

        return matrix[i][j] + min(st,min(ld,rd));
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^2)
   SC: O(n^2)
 */
int solveMemo(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        int n = matrix.size();
        if( j<0 || j>=n || i<0 ){
            return INT_MAX;
        }

        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int st = solveMemo(i-1,j,matrix,dp);
        int ld = solveMemo(i-1,j-1,matrix,dp);
        int rd = solveMemo(i-1,j+1,matrix,dp);

        return dp[i][j] =  matrix[i][j] + min(st,min(ld,rd));
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n^2)
   SC: O(n^2)
*/
int minFallingPathSumTab(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        
        for(int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }


            for(int i = 1; i<n; i++){
                for(int j = 0; j<n; j++){
                    int st = INT_MAX;
                    if(i>0){
                        st = dp[i-1][j];
                    }
                    int ld = INT_MAX;
                    int rd = INT_MAX;
                    if(j>0 ){
                        ld = dp[i-1][j-1];
                    }
                    if( j<n-1){
                       rd = dp[i-1][j+1];
                    }

                    dp[i][j] = matrix[i][j] + min(st,min(ld,rd));
                }
            }
            int mini = INT_MAX;
            for(int j = 0; j<n; j++){
                mini = min(mini,dp[n-1][j]);
            }


            return mini;

}


/* 
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(n^2)
   SC: O(n)
 */
int minFallingPathSumSpaceOP(vector<vector<int>>& matrix) {
        int n = matrix.size();
      
        vector<int> prev(n,0);
        
        for(int j = 0; j<n; j++){
           prev[j] = matrix[0][j];
        }


            for(int i = 1; i<n; i++){
                vector<int> curr(n,0);
                for(int j = 0; j<n; j++){
                    int st = INT_MAX;
                    if(i>0){
                        st = prev[j];
                    }
                    int ld = INT_MAX;
                    int rd = INT_MAX;
                    if(j>0 ){
                        ld = prev[j-1];
                    }
                    if( j<n-1){
                       rd = prev[j+1];
                    }

                    curr[j] = matrix[i][j] + min(st,min(ld,rd));
                }
                prev = curr;
            }
            int mini = INT_MAX;
            for(int j = 0; j<n; j++){
                mini = min(mini,prev[j]);
            }


            return mini;

}

int main() {

    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int n = matrix.size();

    int ansRec = INT_MAX;
    for (int j = 0; j < n; j++) {
        ansRec = min(ansRec, solveRec(n - 1, j, matrix));
    }
    cout << "Recursion:" << ansRec << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ansMemo = INT_MAX;
    for (int j = 0; j < n; j++) {
        ansMemo = min(ansMemo, solveMemo(n - 1, j, matrix, dp));
    }
    cout << "Memoization:" << ansMemo << endl;

    cout << "Tabulation:" << minFallingPathSumTab(matrix) << endl;
    cout << "Space Optimized:" << minFallingPathSumSpaceOP(matrix) << endl;

    return 0;
}
