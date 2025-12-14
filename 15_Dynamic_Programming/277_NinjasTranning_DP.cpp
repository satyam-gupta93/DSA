#include <bits/stdc++.h>
using namespace std;

/*
1. RECURSION 
TC: O(3^n)
SC: O(n)   // recursion stack
*/
int solveRec(int day,int last,vector<vector<int>>& arr){
        
        if(day==0){
            
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i!=last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            
            return maxi;
        }
        
        int maxi = 0;
        for(int i = 0; i<3; i++){
            if(last!=i){
                int val = arr[day][i] + solveRec(day-1,i,arr);
                maxi = max(maxi,val);
            }
                
        }
        
        return maxi;
}

/*
 2. MEMOIZATION 
TC: O(n)
SC: O(n)   // dp table + recursion stack
*/
int solveMemo(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
        
        if(day==0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i!=last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            
            return maxi;
        }
        
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        
        int maxi = 0;
        for(int i = 0; i<3; i++){
            if(i!=last){
                int val = arr[day][i] + solveMemo(day-1,i,arr,dp);
                maxi = max(val,maxi);
            }
        }
        
        return dp[day][last] = maxi;
}
   

/*
 3. TABULATION 
TC: O(n)
SC: O(n)   // dp table
*/
int solveTabulation(vector<vector<int>>& arr) {
        // Code here
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (4,0));
        
        for(int l = 0; l<4; l++){
            int maxi = 0;
            for(int t = 0; t<3; t++){
                if(l!=t){
                    maxi = max(maxi,arr[0][t]);
                }
                
            }
            dp[0][l] = maxi;
            
        }
        
        for(int d = 1; d<n; d++){
            for(int l = 0; l<4; l++){
                int maxi = 0;
                for(int t = 0; t<3; t++){
                    if(l!=t){
                         int val = arr[d][t] + dp[d-1][t];
                        dp[d][l] = max(dp[d][l],val);
                    }
                   
                }
            }
        }
        
        return dp[n-1][3];
        
        
}

/*
4. SPACE OPTIMIZED
TC: O(n)
SC: O(1)
*/
int solveSpaceOP(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<int> prev(4,0);
      
        
        for(int l = 0; l<4; l++){
            int maxi = 0;
            for(int t = 0; t<3; t++){
                if(l!=t){
                    maxi = max(maxi,arr[0][t]);
                }
                
            }
           prev[l] = maxi;
            
        }
        
        for(int d = 1; d<n; d++){
            vector<int> curr(4,0);
            for(int l = 0; l<4; l++){
               
                for(int t = 0; t<3; t++){
                    if(l!=t){
                       
                         int val = arr[d][t] + prev[t];
                            curr[l]= max(curr[l],val);
                    }
                   
                }
            }
            prev = curr;
        }
        
        return prev[3];
        
        
}


int main() {
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };

    int n = arr.size();

    cout << "Recursion:"<< solveRec(n - 1, 3, arr) << endl;

    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << "Memoization:"<< solveMemo(n - 1, 3, arr, dp) << endl;

    cout << "Tabulation:"<< solveTabulation(arr) << endl;

    cout << "Space Optimized:"<< solveSpaceOP(arr) << endl;

    return 0;
}
