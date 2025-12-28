#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: O(2^(n+m))
   SC: O(n+m)
*/
int solveRec(int indx1, int indx2, string & text1, string & text2) {

        if(indx1 < 0 || indx2<0 ){
            return 0;
        }

        if( text1[indx1] == text2[indx2] ){
            return 1 + solveRec(indx1-1,indx2-1,text1,text2);
        }

        return max(solveRec(indx1-1,indx2,text1,text2),solveRec(indx1,indx2-1,text1,text2));
}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * m)
   SC: O(n * m)
*/
    int solveMemo(int indx1, int indx2,string text1,string text2, vector<vector<int>> &dp){

        if(indx1<0 || indx2<0 ){
            return 0;
        }

        if(dp[indx1][indx2]!=-1){
            return dp[indx1][indx2];
        }

        if(text1[indx1] == text2[indx2] ){
            return dp[indx1][indx2] =  1 + solveMemo(indx1-1,indx2-1,text1,text2,dp);
        }

        return dp[indx1][indx2] =  max( solveMemo(indx1-1,indx2,text1,text2,dp),solveMemo(indx1,indx2-1,text1,text2,dp) );
    }

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m)
   SC: O(n * m)
 */
int lcsTab(string &text1, string &text2) {

        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));


        for(int i1 = 1; i1<=n1; i1++){
            for(int i2 = 1; i2<=n2; i2++){
  
                if(text1[i1-1] == text2[i2-1] ){
                     dp[i1][i2] =  1 + dp[i1-1][i2-1];
                }else{
                     dp[i1][i2] =  max( dp[i1-1][i2],  dp[i1][i2-1]);
                }

              


            }
        }


        return dp[n1][n2];
}

/*
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * m)
   SC: O(m)
*/
int longestCommonSubsequence(string text1 , string text2) {

        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        vector<int> prev(n2+1,0);

        for(int i1 = 1; i1<=n1; i1++){
            vector<int> curr(n2+1,0);
            for(int i2 = 1; i2<=n2; i2++){
  
                if(text1[i1-1] == text2[i2-1] ){
                     curr[i2] =  1 + prev[i2-1];
                }else{
                     curr[i2] =  max( prev[i2],  curr[i2-1]);
                }

              


            }
            prev = curr;
        }


        return prev[n2];
}


int main() {

    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size(), m = text2.size();

    cout << "Recursion: "<< solveRec(n - 1, m - 1, text1, text2) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization:" << solveMemo(n - 1, m - 1, text1, text2, dp) << endl;

    cout << "Tabulation:"<< lcsTab(text1, text2) << endl;

    cout << "Space Optimized:"<< longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
