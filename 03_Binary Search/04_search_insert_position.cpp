#include <iostream>
#include <vector>
using namespace std;

/*
 * 04. Search Insert Position (LeetCode 35)
 * Difficulty: Basic
 * 
 * Description: Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. If not, return the index where it 
 * would be if it were inserted in order.
 * 
 * Note: Equivalent to finding the lower bound of target.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid; // target found
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        // 's' always ends at the insertion point
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    cout << "Array: {1, 3, 5, 6}" << endl;
    cout << "Insert 5 -> index: " << sol.searchInsert(nums, 5) << " (expected 2)" << endl;
    cout << "Insert 2 -> index: " << sol.searchInsert(nums, 2) << " (expected 1)" << endl;
    cout << "Insert 7 -> index: " << sol.searchInsert(nums, 7) << " (expected 4)" << endl;
    cout << "Insert 0 -> index: " << sol.searchInsert(nums, 0) << " (expected 0)" << endl;

    return 0;
}
