#include <bits/stdc++.h>
using namespace std;

// Count subarrays with exactly k odd numbers.
//
// Trick:
// exactly k = atMost(k) - atMost(k-1)
//
// Works because we're counting based on a monotonic property (odd count).

// TC: O(n)
// SC: O(1)
    int numberAtMost(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int i = 0;
        int j = 0;
        int n = nums.size();
        int oddCount = 0;

        int ans = 0;


        while(j<n){
            if(nums[j]%2!=0){
                oddCount++;
            }

            while( oddCount>k ){
                if(nums[i]%2!=0){
                    oddCount--;
                }
                i++;
            }

            ans += (j-i+1);
            j++;

        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberAtMost(nums,k) - numberAtMost(nums,k-1);
    }


int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << numberOfSubarrays(nums, k);
    return 0;
}
