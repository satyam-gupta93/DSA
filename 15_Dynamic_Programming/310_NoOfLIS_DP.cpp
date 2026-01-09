#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
        int n =  nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if( nums[i] > nums[j] && dp[i] < 1 + dp[j] ){
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }else if(nums[i] > nums[j] && dp[i] == 1 + dp[j]){
                    cnt[i] += cnt[j];
                }
                maxi = max(maxi,dp[i]);
            }
        }

        int count = 0;

        for(int i = 0; i<n ;i++){
            if(dp[i] == maxi){
                count += cnt[i];
            }
        }



        return count;
}
int main() {

    vector<int> nums = {1 ,2, 5, 3 ,2};
    int n = nums.size();
    int ans = findNumberOfLIS(nums);
    cout << "Number of Longest Incresing Subsequnece:"<<ans << endl;

    

    return 0;
}
