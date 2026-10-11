#include <iostream>
#include <vector>
using namespace std;

/*
 * 07. Search in Rotated Sorted Array I (LeetCode 33)
 * Difficulty: Core
 * 
 * Description: Given an integer array nums sorted in ascending order with distinct values,
 * which is rotated at an unknown pivot, and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * Logic (Identify Sorted Half):
 * In a rotated sorted array, at least one half (left or right) is guaranteed to be sorted.
 * 1. If nums[s] <= nums[mid], the left half is sorted:
 *    - If target lies in [nums[s], nums[mid]), search left (e = mid - 1).
 *    - Else search right (s = mid + 1).
 * 2. Else, the right half is sorted:
 *    - If target lies in (nums[mid], nums[e]], search right (s = mid + 1).
 *    - Else search left (e = mid - 1).
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (arr[s] <= arr[mid]) {
                if (arr[s] <= target && target < arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (arr[mid] < target && target <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Array: {4, 5, 6, 7, 0, 1, 2}, Target: " << target << endl;
    cout << "Index: " << sol.search(nums, target) << " (expected 4)" << endl;

    int target2 = 3;
    cout << "Target: " << target2 << " -> Index: " << sol.search(nums, target2) << " (expected -1)" << endl;

    return 0;
}
