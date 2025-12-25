#include <bits/stdc++.h>
using namespace std;

/* 
   1. RECURSION (Brute Force)
   TC: O(2^n)
   SC: O(n)
 */
int solveRec(int indx, int targetSum, vector<int>& nums) {

        if(indx==0){
            if( targetSum == 0 && nums[0] == 0 ){
                return 2;
            }
            if(targetSum == 0 || targetSum == nums[0]){
                return 1;
            }

            return 0;
        }

        int take = 0;
        if( nums[indx]<= targetSum ){
            take = solveRec(indx-1,targetSum-nums[indx],nums);
        }
        int skip = solveRec(indx-1,targetSum,nums);

        return take + skip;
}

/* 
   2. MEMOIZATION (Top-Down DP)
   TC: O(n * sumP)
   SC: O(n * sumP)
 */
int solveMemo(int indx, int targetSum,
              vector<int>& nums,
              vector<vector<int>>& dp) {

        if(indx==0){
            if( targetSum == 0 && nums[0] == 0 ){
                return 2;
            }
            if(targetSum == 0 || targetSum == nums[0]){
                return 1;
            }

            return 0;
        }

        if(dp[indx][targetSum]!=-1){
            return dp[indx][targetSum];
        }

        int take = 0;
        if( nums[indx]<= targetSum ){
            take = solveMemo(indx-1,targetSum-nums[indx],nums,dp);
        }
        int skip = solveMemo(indx-1,targetSum,nums,dp);

        return dp[indx][targetSum] =  take + skip;
}

/*
   3. TABULATION (Bottom-Up DP)
   TC: O(n * sumP)
   SC: O(n * sumP)
*/
int findTargetSumWaysTab(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if( (sum+target)%2 != 0 || abs(target)>sum){
            return 0;
        }
      
        int sumP = (sum + target)/2;
        vector<vector<int>> dp(n,vector<int> (sumP+1,0));

        if(nums[0] == 0){
            dp[0][0] = 2;
        }else{
            dp[0][0] = 1;
            if(nums[0] <= sumP){
                dp[0][nums[0]] = 1;
            }
        }

        for(int i = 1; i<n; i++){
            for(int s = 0; s<=sumP; s++){
                int take = 0;
                if( nums[i]<= s ){
                    take = dp[i-1][s-nums[i]];
                }
                int skip = dp[i-1][s];

                dp[i][s] = take + skip;
            }
        }


        return dp[n-1][sumP];
}

/*
   4. SPACE OPTIMIZATION (BEST)
   TC: O(n * sumP)
   SC: O(sumP)
*/
int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if( (sum+target)%2 != 0 || abs(target)>sum){
            return 0;
        }
      
        int sumP = (sum + target)/2;
        vector<vector<int>> dp(n,vector<int> (sumP+1,0));
        vector<int> prev(sumP+1,0);
        if(nums[0] == 0){
           prev[0] = 2;
        }else{
            prev[0] = 1;
            if(nums[0] <= sumP){
               prev[nums[0]] = 1;
            }
        }

        for(int i = 1; i<n; i++){
            vector<int> curr(sumP+1,0);
            for(int s = 0; s<=sumP; s++){
                int take = 0;
                if( nums[i]<= s ){
                    take = prev[s-nums[i]];
                }
                int skip = prev[s];

              curr[s] = take + skip;
            }
            prev = curr;
        }


        return prev[sumP];
}

int main() {

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
    }
    if (abs(target) > sum || (sum + target) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int sumP = (sum + target) / 2;
    int n = nums.size();

    cout << "Recursion:"<< solveRec(n - 1, sumP, nums) << endl;

    vector<vector<int>> dp(n, vector<int>(sumP + 1, -1));
    cout << "Memoization:"<< solveMemo(n - 1, sumP, nums, dp) << endl;

    cout << "Tabulation:"<< findTargetSumWaysTab(nums, target) << endl;

    cout << "Space Optimized:"<< findTargetSumWays(nums, target) << endl;

    return 0;
}
