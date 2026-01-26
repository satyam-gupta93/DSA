#include <bits/stdc++.h>
using namespace std;

// Find the longest subarray containing at most k zeros
// We can flip at most k zeros to ones.
//
// Example:
// nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: Flip two zeros to get longest window of 1s.

// TC: O(n)
// SC: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int zeroCount = 0;
        int ans = 0;
        int n = nums.size();

        while(j<n){
            if(nums[j]==0){
                zeroCount++;
            }

            while(zeroCount>k){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }


        return ans;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << longestOnes(nums, k);
    return 0;
}
