#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1] ){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                     dp[i][j] = max( dp[i-1][j],dp[i][j-1] );
                }
            }
        }

        int LCS = dp[n][m];

        int rem1 = n - LCS;
        int rem2 = m - LCS;


        return rem1 + rem2;
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << "Min deletion make string same:"<<minDistance(s1,s2) << endl;

    return 0;
}