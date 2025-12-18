#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: O(9^n)
   SC: O(n)
*/
int solveRec(int i, int j1, int j2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j1<0 || j2<0 || j1>=m || j2>=m || i>=n){
            return INT_MIN;
        }
        
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        int maxi = INT_MIN;
        
        
        for(int k1 = -1; k1<=1; k1++){
            for(int k2 = -1; k2<=1; k2++){
                int value;
                if(j1==j2){
                    value = grid[i][j1];
                }else{
                    value = grid[i][j1] + grid[i][j2];
                }
                
                maxi = max(maxi,value + solveRec(i+1,j1+k1,j2+k2,grid));
            }
        }
        
        return maxi;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * m * m * 9)
   SC: O(n * m * m)
*/
int solveMemo(int i, int j1, int j2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j1<0 || j2<0 || j1>=m || j2>=m || i>=n){
            return INT_MIN;
        }
        
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        
        int maxi = INT_MIN;
        
        
        for(int k1 = -1; k1<=1; k1++){
            for(int k2 = -1; k2<=1; k2++){
                int value;
                if(j1==j2){
                    value = grid[i][j1];
                }else{
                    value = grid[i][j1] + grid[i][j2];
                }
                
                maxi = max(maxi,value + solveMemo(i+1,j1+k1,j2+k2,grid,dp));
            }
        }
        
        return dp[i][j1][j2] =  maxi;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * m * m * 9)
   SC: O(n * m * m)
*/
int maxChocolateTab(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int>(m,0)));
        
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int val;
                if(j1 == j2){
                    val = grid[n-1][j1];
                }else{
                    val = grid[n-1][j1] + grid[n-1][j2];
                }
                
                dp[n-1][j1][j2] = val;
            }
        }
        
        for(int i = n-2 ;i>=0 ;i--){
            for(int j1 = 0; j1<m; j1++){
                for(int j2 = 0; j2<m; j2++){
                    
                    int maxi = INT_MIN;
                    int val = 0;
                    
                    if(j1 == j2){
                        val = grid[i][j1];
                        
                    }else{
                        val = grid[i][j1] + grid[i][j2];
                    }
                    
                    for(int k1 = -1; k1<=1; k1++){
                        for(int k2 = -1; k2<=1; k2++){
                          
                          int nj1 = j1+ k1;
                          int nj2 = j2+ k2;
                          
                          if(nj1>=0 && nj1<m && nj2>=0 && nj2<m){
                              maxi = max(maxi,val+ dp[i+1][nj1][nj2]);
                              
                              
                          }
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                    
                    
                }
            }
        }
        
        return dp[0][0][m-1];
}

/* 
   4. SPACE OPTIMIZATION
   TC: O(n * m * m * 9)
   SC: O(m * m)
*/
int maxChocolateSpaceOP(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> front(m,vector<int>(m,0));
       
        
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int val;
                if(j1 == j2){
                    val = grid[n-1][j1];
                }else{
                    val = grid[n-1][j1] + grid[n-1][j2];
                }
                
                front[j1][j2] = val;
            }
        }
        
        for(int i = n-2 ;i>=0 ;i--){
             vector<vector<int>> curr(m,vector<int>(m,0));
            for(int j1 = 0; j1<m; j1++){
                for(int j2 = 0; j2<m; j2++){
                    
                    int maxi = INT_MIN;
                    int val = 0;
                    
                    if(j1 == j2){
                        val = grid[i][j1];
                        
                    }else{
                        val = grid[i][j1] + grid[i][j2];
                    }
                    
                    for(int k1 = -1; k1<=1; k1++){
                        for(int k2 = -1; k2<=1; k2++){
                          
                          int nj1 = j1+ k1;
                          int nj2 = j2+ k2;
                          
                          if(nj1>=0 && nj1<m && nj2>=0 && nj2<m){
                              maxi = max(maxi,val+ front[nj1][nj2]);
                              
                              
                          }
                        }
                    }
                    
                    curr[j1][j2] = maxi;
                    
                    
                }
            }
            front = curr;
        }
        
        return front[0][m-1];
}


int main() {

    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    int n = grid.size();
    int m = grid[0].size();

    cout << "Recursion:"<< solveRec(0, 0, m - 1, grid) << endl;

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << "Memoization:"<< solveMemo(0, 0, m - 1, grid, dp) << endl;

    cout << "Tabulation:"<< maxChocolateTab(grid) << endl;

    cout << "Space Optimized:"<< maxChocolateSpaceOP(grid) << endl;

    return 0;
}
