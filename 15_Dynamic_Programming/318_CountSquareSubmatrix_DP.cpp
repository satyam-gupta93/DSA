#include <bits/stdc++.h>
using namespace std;

/*
   1: Tabulation (2D DP)
   TC: O(n*m)
   SC: O(n*m)
*/
int countSquaresDP(vector<vector<int>>& matrix) {
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

/* 
   2: Space Optimized DP
   TC: O(n*m)
   SC: O(m)
 */
int countSquaresSpaceOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

       
        vector<int>prev(m,0); 
         int sum = 0;
        for(int j = 0; j<m; j++){
            prev[j] = matrix[0][j];
            sum += matrix[0][j];
        }
       
       
        for(int i = 1; i<n;i++){
            
            vector<int>curr(m,0); 
            for(int j = 0; j<m; j++){
                if(j == 0){
                    curr[0] = matrix[i][0];
                    sum+=matrix[i][0];
                    continue;
                }
                if(matrix[i][j] == 1){
                    curr[j] = 1 + min(prev[j],min(curr[j-1],prev[j-1]));
                    sum += curr[j];
                }
                
               
            }
            prev = curr;
        }
        
       return sum;
}


int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout << "2D DP Answer:"<< countSquaresDP(matrix) << endl;

    cout << "Space Optimized Answer:"<< countSquaresSpaceOptimized(matrix) << endl;

    return 0;
}
