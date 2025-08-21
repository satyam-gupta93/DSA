#include<iostream>
#include<vector>
using namespace std;




void solve(vector<int>& nums, vector<int>output,int indx, vector<vector<int>> &ans){

    if(indx>=nums.size()){
        ans.push_back(output);
        return;

    }
    // exclude 
    solve(nums,output,indx+1,ans);

    // include
    int ele = nums[indx];
    output.push_back(ele);
    solve(nums,output,indx+1,ans);

}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int>output;
        int index = 0;
        solve(nums,output,index,ans);

        return ans;
    }
};

int main(){

}