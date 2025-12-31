#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n + m)
*/
int solveRec(int i, int j, string &word1, string &word2) {

        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if(word1[i] == word2[j]){
            return solveRec(i-1,j-1,word1,word2);
        }
        else{
            int insert = solveRec(i,j-1,word1,word2);
            int deletion = solveRec(i-1,j,word1,word2);
            int replace = solveRec(i-1,j-1,word1,word2);

            return 1 + min(insert,min(deletion,replace));
        }
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * m)
   SC: O(n * m)
*/
int solveMemo(int i, int j, string &word1, string &word2,
              vector<vector<int>> &dp) {

        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if( dp[i][j] != -1 ){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            return dp[i][j] =  solveMemo(i-1,j-1,word1,word2,dp);
        }
        else{
            int insert = solveMemo(i,j-1,word1,word2,dp);
            int deletion = solveMemo(i-1,j,word1,word2,dp);
            int replace = solveMemo(i-1,j-1,word1,word2,dp);

            return dp[i][j]= 1 + min(insert,min(deletion,replace));
        }
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m)
   SC: O(n * m)
*/
int minDistanceTab(string &word1, string &word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i = 0; i<=n; i++){
            dp[i][0] = i;
        }

        for(int j = 0; j<=m; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] =  dp[i-1][j-1];
                }else{
                     int insert = dp[i][j-1];
                     int deletion = dp[i-1][j];
                     int replace = dp[i-1][j-1];

                     dp[i][j]= 1 + min(insert,min(deletion,replace));
                 }
            }
        }

        return dp[n][m];
}

/*
   4. SPACE OPTIMIZED (BEST)
   TC: O(n * m)
   SC: O(m)
*/
int minDistanceSpaceOptimized(string &word1, string &word2) {

        int n = word1.size();
        int m = word2.size();

       
        
        vector<int> prev(m+1,0);
        prev[0] = 0;

         for(int j = 0; j<=m; j++){
            prev[j] = j;
        }



        for(int i = 1; i<=n; i++){
            vector<int> curr(m+1,0);
            curr[0] = i;
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] =  prev[j-1];
                }else{
                     int insert = curr[j-1];
                     int deletion = prev[j];
                     int replace = prev[j-1];

                     curr[j]= 1 + min(insert,min(deletion,replace));
                 }

                
            }
             prev = curr;
        }

        return prev[m];
}


int main() {

    string word1 = "horse";
    string word2 = "ros";

    int n = word1.size();
    int m = word2.size();

    cout << "Recursion:"<< solveRec(n - 1, m - 1, word1, word2) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization:"<< solveMemo(n - 1, m - 1, word1, word2, dp) << endl;

    cout << "Tabulation:"<< minDistanceTab(word1, word2) << endl;

    cout << "Space Optimized:"<< minDistanceSpaceOptimized(word1, word2) << endl;

    return 0;
}
