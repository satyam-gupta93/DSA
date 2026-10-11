#include <iostream>
#include <vector>
using namespace std;

/*
 * 01. Search X in sorted array (LeetCode 704)
 * Difficulty: Basic / Easy
 * 
 * Description: Given a sorted array of integers nums and an integer target,
 * find if target exists in nums. If it exists, return its index, else return -1.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << "Array: {-1, 0, 3, 5, 9, 12}, Target: " << target << endl;
    cout << "Index: " << sol.search(nums, target) << " (expected 4)" << endl;

    int target2 = 2;
    cout << "Target: " << target2 << " -> Index: " << sol.search(nums, target2) << " (expected -1)" << endl;

    return 0;
}
