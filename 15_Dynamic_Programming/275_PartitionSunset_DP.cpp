#include <bits/stdc++.h>
using namespace std;


bool checkTargetSubset(int indx, vector<int>& arr, int target,
                  vector<vector<int>>& dp) {

        if(target==0){
            return true;
        }

        if(indx == 0){
            return arr[indx] == target;
        }

        if(dp[indx][target]!=-1){
            return dp[indx][target];
        }

        bool take = false;
        if(arr[indx]<=target){
            take = checkTargetSubset(indx-1,arr,target-arr[indx],dp);
        }
        bool skip = checkTargetSubset(indx-1,arr,target,dp);

        return dp[indx][target] =  take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1)); 


        return checkTargetSubset(n - 1, nums, target, dp);
    }


int main() {
   

    vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums))
        cout <<"True"<<endl;
    else
        cout <<"False:"<<endl;

    return 0;
}
