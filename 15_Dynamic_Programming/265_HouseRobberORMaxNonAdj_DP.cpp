#include <bits/stdc++.h>
using namespace std;


// PURE RECURSION 
// Time: O(2^n)
int solveRec(int i, vector<int>& nums) {
      if(i>=nums.size()){
            return 0;
        }

        int take = nums[i] + solveRec(i+2,nums);
        int skip = solveRec(i+1,nums);

        return max(take,skip);
}

// 2) MEMOIZATION 
// Time: O(n), Space: O(n)
int solveMemo(int i, vector<int>& nums, vector<int>& dp) {
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int take = nums[i] + solveMemo(i+2,nums,dp);
        int skip = solveMemo(i+1,nums,dp);

        return dp[i] = max(take,skip);
}

// 3) TABULATION 
// Time: O(n), Space: O(n)
int robTabulation(vector<int>& nums) {
    int n = nums.size();

        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }

        return dp[n-1];
}


// 4) SPACE OPTIMIZED DP 
// Time: O(n), Space: O(1)
int robOptimized(vector<int>& nums) {
    int n = nums.size();

        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        int curr;
        for(int i = 2; i<n; i++){
            curr = max(prev1 , nums[i] + prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
}


// MAIN FUNCTION

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Recursion: "<<solveRec(0, nums) << endl;

    vector<int> dp(nums.size(), -1);
    cout << "Memoization: "<< solveMemo(0, nums, dp) << endl;

  
    cout << "Tabulation:"<< robTabulation(nums) << endl;

    cout << "Space Optimized:"<< robOptimized(nums) << endl;

    return 0;
}
