#include <iostream>
#include <vector>
using namespace std;

/*
 * 23. Find Peak Element (LeetCode 162)
 * Difficulty: Core
 * 
 * Description: A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -inf.
 * 
 * Logic:
 * Compare nums[mid] with nums[mid + 1]:
 *  - If nums[mid] < nums[mid + 1]: The slope is ascending to the right. 
 *    There must be a peak on the right side -> s = mid + 1.
 *  - Else: The slope is descending (or mid is a peak).
 *    There must be a peak at mid or to the left -> e = mid.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Array: {1, 2, 3, 1}" << endl;
    cout << "Peak Element Index: " << sol.findPeakElement(nums1) << " (expected 2, value: 3)" << endl;

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Array: {1, 2, 1, 3, 5, 6, 4}" << endl;
    cout << "Peak Element Index: " << sol.findPeakElement(nums2) << " (expected 1 or 5)" << endl;

    return 0;
}
