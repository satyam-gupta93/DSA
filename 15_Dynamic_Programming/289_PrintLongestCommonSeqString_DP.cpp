#include <bits/stdc++.h>
using namespace std;

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m)
   SC: O(n * m)
 */
string lcsTab(string &text1, string &text2) {

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
        string ans ="";
        int i = n1;
        int j = n2;
        while( i > 0 && j > 0 ){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }

        }

        reverse(ans.begin(),ans.end());

        return ans;

     }


int main() {

    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size(), m = text2.size();

    string ans = lcsTab(text1,text2);

    cout<<"Longest Common Sequence:"<<ans<<endl;


    return 0;
}   
