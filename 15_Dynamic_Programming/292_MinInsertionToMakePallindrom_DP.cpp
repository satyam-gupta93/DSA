#include <bits/stdc++.h>
using namespace std;


    
int MinStepPallindrom(string s) {
        int n = s.size();

        string s2 = s;
        reverse(s2.begin(),s2.end());

        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if( s[i-1] == s2[j-1] ){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
  
  
        }



        int LPS =  dp[n][n];

        return n - LPS;
}

int main() {
    string s1 = "ABCDGH";


    cout << "Min Step to make pallindrom:"<< MinStepPallindrom(s1) << endl;

    return 0;
}