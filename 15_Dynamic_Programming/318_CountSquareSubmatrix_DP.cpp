#include <bits/stdc++.h>
using namespace std;


int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        int sum = 0;
        for(int i = 0; i<n;i++){
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }
        for(int j = 1; j<m;j++){
            dp[0][j] = matrix[0][j];
            sum += dp[0][j];
        }
        for(int i = 1; i<n;i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    sum += dp[i][j];
                }
                
               
            }
        }
        
       return sum;
}


int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout <<"Total square submatrices with all 1s:"<<countSquares(matrix) << endl;

    return 0;
}
