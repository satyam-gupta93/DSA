#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n + m)
*/
    int solveRec(int i,int j,string s, string t){
        
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }


        if( s[i] == t[j] ){
            return solveRec(i-1,j-1,s,t) + solveRec( i-1,j,s,t);
        }

        return solveRec( i-1,j,s,t);
      

        
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * m)
   SC: O(n * m)
*/
long long solveMemo(int i, int j, string &s, string &t,
                    vector<vector<long long>> &dp) {

        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        if( s[i] == t[j] ){
            return dp[i][j] =  solveMemo(i-1,j-1,s,t,dp) + solveMemo( i-1,j,s,t,dp);
        }

        return dp[i][j] = solveMemo( i-1,j,s,t,dp);
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m)
   SC: O(n * m)
*/
long long numDistinctTab(string &s, string &t) {

        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long >> dp( n+1,vector< unsigned long long>(m+1,0) );

        for(int i = 0; i<=n ;i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
}

/* 
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * m)
   SC: O(m)
 */
long long numDistinctSpaceOptimized(string &s, string &t) {

        int n = s.size();
        int m = t.size();

        
        vector< unsigned long long> prev(m+1,0);

        prev[0] = 1;

        for(int i = 1; i<=n; i++){
            vector< unsigned long long> curr(m+1,0);
            curr[0] = 1;
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }else{
                   curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
}

int main() {

    string s = "rabbbit";
    string t = "rabbit";

    int n = s.size();
    int m = t.size();

    cout << "Recursion:" << solveRec(n - 1, m - 1, s, t) << endl;

    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    cout << "Memoization:"<< solveMemo(n - 1, m - 1, s, t, dp) << endl;

    cout << "Tabulation:"<< numDistinctTab(s, t) << endl;

    cout << "Space Optimized:"<< numDistinctSpaceOptimized(s, t) << endl;

    return 0;
}
