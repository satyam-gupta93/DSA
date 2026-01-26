#include <bits/stdc++.h>
using namespace std;

// Count subarrays with sum exactly equal to goal.
// Trick:
// subarrays with sum == goal
// = subarrays with sum <= goal - subarrays with sum <= (goal - 1)
//
// Works because nums contains only 0s and 1s.

// TC: O(n)
// SC: O(1)
    int numSubarraysAtMostWithSum(vector<int>& nums, int goal){
         int n = nums.size();

         if(goal<0){
            return 0;
         }
      
            int i = 0;
            int j = 0;
            int count = 0;
            int sum = 0;
            while( j < n ){
                sum += nums[j];

                while( sum > goal ){
                    sum -= nums[i];
                    i++;
                }

                
                    count += (j - i +1);
            
                j++;
            }



            return count;   
    }

// Subarrays with sum == goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
       return numSubarraysAtMostWithSum(nums,goal) - numSubarraysAtMostWithSum(nums,goal-1);

    }

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal);
    return 0;
}
