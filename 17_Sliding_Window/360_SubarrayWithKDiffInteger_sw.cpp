#include <bits/stdc++.h>
using namespace std;

// Count subarrays with exactly k distinct integers.
//
// Trick:
// exactly k = atMost(k) - atMost(k-1)
//
// TC: O(n)
// SC: O(1)   
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k){
         int i = 0;
        int j = 0;

        int count = 0;
        int n = nums.size();

        unordered_map<int,int> m;

        while(j<n){
            m[nums[j]]++;

            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
                
            }

           
                count += (j-i+1);
      

            j++;
        }

        return count;


    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarraysWithAtMostKDistinct(nums,k) - subarraysWithAtMostKDistinct(nums , k-1);
    }

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << subarraysWithKDistinct(nums, k);
    return 0;
}
