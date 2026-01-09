#include <bits/stdc++.h>
using namespace std;
    
vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size();

        vector<int> ans;
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = 1;
        int maxIndx = 0;

        sort(nums.begin(),nums.end());

        for(int i = 1; i<n; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if( nums[i]%nums[j] == 0 && dp[i] < 1 + dp[j] ){
                    dp[i] = max(dp[i],1 + dp[j]);
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                maxIndx = i;
            }
        }

        ans.push_back(nums[maxIndx]);

        while(hash[maxIndx] != maxIndx){
            maxIndx = hash[maxIndx];
            ans.push_back(nums[maxIndx]);
        }



        return ans;
}
int main(){
    vector<int> arr = {10, 20, 9, 33, 21, 50, 41, 60, 80};
    
    vector<int> ans = largestDivisibleSubset(arr);
    cout<<"Longest Divisible Subset:";
    for(int i =0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
}
