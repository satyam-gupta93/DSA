#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION
   TC: Exponential
   SC: O(n) recursion stack
*/
int solveRec(int i, int j, vector<vector<int>>& triangle) {
        int n = triangle.size();

        if( i == n-1 ){
            return triangle[i][j];
        }

        int down = solveRec(i+1,j,triangle);
        int dignl = solveRec(i+1,j+1,triangle);

        return triangle[i][j] + min(down,dignl);
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n*n)
   SC: O(n*n)
*/
int solveMemo(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

    int n = triangle.size();

        if( i == n-1 ){
            return triangle[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down = solveMemo(i+1,j,triangle,dp);
        int dignl = solveMemo(i+1,j+1,triangle,dp);

        return dp[i][j] =  triangle[i][j] + min(down,dignl);
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n*n)
   SC: O(n*n)
*/
int minimumTotalTab(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int j = 0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                int up = dp[i+1][j];
                int dg = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(up,dg);
            }
        }

        return dp[0][0];
      
}


/* 
   4. SPACE OPTIMIZATION (1D DP)
   TC: O(n*n)
   SC: O(n)
 */
int minimumTotalSpaceOP(vector<vector<int>>& triangle) {

        int n = triangle.size();
       
        vector<int> front(n,0);

        for(int j = 0; j<n; j++){
            front[j] = triangle[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            vector<int> curr(i+1,0);
            for(int j = 0; j<=i; j++){
                int up = front[j];
                int dg = front[j+1];

                curr[j]= triangle[i][j] + min(up,dg);
            }
             front = curr;
        }

        return front[0];
}

int main() {

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int n = triangle.size();

    cout << "Recursion:"<< solveRec(0, 0, triangle) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization:"<< solveMemo(0, 0, triangle, dp) << endl;

    cout << "Tabulation:"<< minimumTotalTab(triangle) << endl;

    cout << "Space Optimized:"<< minimumTotalSpaceOP(triangle) << endl;

    return 0;
}
