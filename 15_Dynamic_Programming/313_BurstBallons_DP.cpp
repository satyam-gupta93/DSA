#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: Exponential
   SC: O(n) recursion stack
*/
int solveRec(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }

        int maxi = INT_MIN;

        for(int k = i; k<=j; k++){
            int cost = ( nums[i-1] * nums[k] * nums[j+1] ) + solveRec(i,k-1,nums) + solveRec(k+1,j,nums);
            maxi = max(maxi,cost);
        }

        return maxi;

}

/*
   2. MEMOIZATION (Top-Down DP)
   TC: O(n^3)
   SC: O(n^2) + recursion stack
*/
int solveMemo(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int maxi = INT_MIN;

        for(int k = i; k<=j; k++){
            int cost = ( nums[i-1] * nums[k] * nums[j+1] ) + solveMemo(i,k-1,nums,dp) + solveMemo(k+1,j,nums,dp);
            maxi = max(maxi,cost);
        }

        return dp[i][j] =  maxi;

}

/* 
   3. TABULATION (Bottom-Up DP)
   TC: O(n^3)
   SC: O(n^2)
*/
int maxCoinsTab(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(),1);

        int n = nums.size();

        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        
        for(int i = n-2; i>=1; i--){
            for(int j = i; j<=n-2;j++){
                int maxi = INT_MIN;
                for(int k = i; k<=j; k++){
                    int cost = ( nums[i-1] * nums[k] * nums[j+1] ) +dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }

                dp[i][j] = maxi;

            }
        }

        return dp[1][n-2];
}


int main() {

    vector<int> nums = {3, 1, 5, 8};

    vector<int> nums1 = nums;
    nums1.push_back(1);
    nums1.insert(nums1.begin(), 1);

    int n = nums1.size();

    cout << "Recursion:"<< solveRec(1, n - 2, nums1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization:"<< solveMemo(1, n - 2, nums1, dp) << endl;

    cout << "Tabulation:"<< maxCoinsTab(nums) << endl;

    return 0;
}
