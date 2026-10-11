#include <iostream>
#include <vector>
using namespace std;

/*
 * 06. First and Last Occurrence (LeetCode 34)
 * Difficulty: Core
 * 
 * Description: Given an array of integers nums sorted in non-decreasing order, 
 * find the starting and ending position of a given target value.
 * If target is not found in the array, return {-1, -1}.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

int firstOcc(const vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) {
            ans = mid;
            e = mid - 1; // look in left half for earlier occurrence
        } else if (nums[mid] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOcc(const vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) {
            ans = mid;
            s = mid + 1; // look in right half for later occurrence
        } else if (nums[mid] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> res = sol.searchRange(nums, target);
    cout << "Array: {5, 7, 7, 8, 8, 10}, Target: " << target << endl;
    cout << "First Occurrence: " << res[0] << ", Last Occurrence: " << res[1] << " (expected [3, 4])" << endl;

    int target2 = 6;
    vector<int> res2 = sol.searchRange(nums, target2);
    cout << "Target: " << target2 << " -> [" << res2[0] << ", " << res2[1] << "] (expected [-1, -1])" << endl;

    return 0;
}
