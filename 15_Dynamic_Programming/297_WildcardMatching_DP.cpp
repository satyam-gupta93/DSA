#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n + m)
*/
bool solveRec(int i, int j, string &s, string &p) {

        if( i < 0 && j<0  ){
            return true;
        }
        if( i>=0 && j<0 ){
            return false;
        }
        if( i<0 && j>=0 ){
            for(int k = 0; k<=j;k++){
                if( p[k] != '*' ){
                    return false;
                }
            }
            return true;
        }


        if( s[i] == p[j] || p[j] == '?' ){
            return solveRec(i-1,j-1,s,p);
        }

        if( p[j] == '*' ){
            return solveRec(i,j-1,s,p) || solveRec(i-1,j,s,p);
        }

        return false;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * m)
   SC: O(n * m)
*/
bool solveMemo(int i, int j, string &s, string &p,
               vector<vector<int>> &dp) {

        if( i < 0 && j<0  ){
            return true;
        }
        if( i>=0 && j<0 ){
            return false;
        }
        if( i<0 && j>=0 ){
            for(int k = 0; k<=j;k++){
                if( p[k] != '*' ){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] !=-1){
            return dp[i][j];
        }


        if( s[i] == p[j] || p[j] == '?' ){
            return dp[i][j] =  solveMemo(i-1,j-1,s,p,dp);
        }

        if( p[j] == '*' ){
            return dp[i][j] =  solveMemo(i,j-1,s,p,dp) || solveMemo(i-1,j,s,p,dp);
        }

        return dp[i][j] = false;
}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m)
   SC: O(n * m)
*/
bool isMatchTab(string &s, string &p) {

        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,false));

        dp[0][0] = true;

        for(int i = 1; i<=n;i++){
            dp[i][0] = false; 
        }

        for(int j = 1; j<=m; j++){
            bool flag  = true;
            for(int k = 0; k<j; k++){
                if(p[k]!='*'){
                   flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if( p[j-1] == '*' ){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false;
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
bool isMatchSpaceOptimized(string &s, string &p) {

        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        vector<int> prev(m+1,-1);

        prev[0] = true;

        // for(int i = 1; i<=n;i++){
        //     dp[i][0] = false; 
        // }

        for(int j = 1; j<=m; j++){
            bool flag  = true;
            for(int k = 0; k<j; k++){
                if(p[k]!='*'){
                   flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i<=n; i++){
            vector<int> curr(m+1,-1);
            curr[0] = false;
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }else if( p[j-1] == '*' ){
                    curr[j] = prev[j] || curr[j-1];
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
}

int main() {

    string s = "adceb";
    string p = "*a*b";

    int n = s.size();
    int m = p.size();

    cout << "Recursion:"<< solveRec(n - 1, m - 1, s, p) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization:"<< solveMemo(n - 1, m - 1, s, p, dp) << endl;

    cout << "Tabulation:"<< isMatchTab(s, p) << endl;

    cout << "Space Optimized:"<< isMatchSpaceOptimized(s, p) << endl;

    return 0;
}
