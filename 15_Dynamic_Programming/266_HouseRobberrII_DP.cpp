#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr){

        int n = arr.size();

        if(n==0){
            return 0;
        }
        if(n==1){
            return arr[0];
        }

        int prev2 = arr[0];
        int prev1 = max(arr[0],arr[1]);

        for(int i = 2; i<n; i++){
            int curr = max(prev1,arr[i]+prev2);

            prev2 = prev1;
            prev1 = curr;

        }

        return prev1;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
    
       vector<int> first(nums.begin()+1,nums.end());
       vector<int> second(nums.begin(),nums.end()-1);

       return max(solve(first),solve(second));
}

int main() {
    vector<int> nums = {2, 3, 2};

    cout << "Maximum amount that can be robbed:" << rob(nums) << endl;

    return 0;
}