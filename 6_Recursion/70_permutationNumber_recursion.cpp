#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Your solve function
void solve(vector<int>& nums, vector<vector<int>>& ans, int indx) {
    if (indx >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = indx; i < nums.size(); i++) {
        swap(nums[i], nums[indx]);
        solve(nums, ans, indx + 1);
        swap(nums[i], nums[indx]); // backtrack
    }
}

// Wrapper function
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, ans, 0);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    // Print using index-based for loops
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
