#include <bits/stdc++.h>
using namespace std;

/*
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n)
*/
    int solveRec(int indx,int prevIndx,vector<int>& nums){
        if(indx == nums.size()){
            return 0;
        }

        int take = INT_MIN;
        if( prevIndx == -1 || nums[indx]>nums[prevIndx] ){
            take = 1 + solveRec(indx+1,indx,nums);
        }
        int skip = solveRec(indx+1,prevIndx,nums);

        return max(take,skip);

}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^2)
   SC: O(n^2)
*/
    int solveMemo(int indx,int prevIndx,vector<int>& nums,vector<vector<int>> &dp){
        if(indx == nums.size()){
            return 0;
        }

        if(dp[indx][prevIndx+1] != -1){
            return dp[indx][prevIndx+1];
        }

        int take = INT_MIN;
        if( prevIndx == -1 || nums[indx]>nums[prevIndx] ){
            take = 1 + solveMemo(indx+1,indx,nums,dp);
        }
        int skip = solveMemo(indx+1,prevIndx,nums,dp);

        return dp[indx][prevIndx+1] = max(take,skip);

}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n^2)
   SC: O(n^2)
 */
int lengthOfLISTab(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int i = n -1; i>= 0; i--){
            for(int j = i-1; j>=-1; j--){
                int take =  INT_MIN;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1+ dp[i+1][i+1];
                }
                int skip = dp[i+1][j+1];

                dp[i][j+1] = max(take,skip);
            }
        }


        return dp[0][0];
}

/* 
   4. SPACE OPTIMIZED
   TC: O(n^2)
   SC: O(n)
*/
int lengthOfLISSpaceOptimized(vector<int>& nums) {

        int n = nums.size();
       
        vector<int> front(n+1,0);

        for(int i = n -1; i>= 0; i--){
            vector<int> curr(n+1,0);
            for(int j = i-1; j>=-1; j--){
                int take =  INT_MIN;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1+ front[i+1];
                }
                int skip = front[j+1];

                curr[j+1] = max(take,skip);
            }
            front = curr;
        }


    return front[0];
}


int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Recursion:"<< solveRec(0, -1, nums) << endl;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << "Memoization:"<< solveMemo(0, -1, nums, dp) << endl;

    cout << "Tabulation:"<< lengthOfLISTab(nums) << endl;

    cout << "Space Optimized:"<< lengthOfLISSpaceOptimized(nums) << endl;

    return 0;
}
