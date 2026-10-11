#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 15. Find the Smallest Divisor Given a Threshold (LeetCode 1283)
 * Difficulty: Core
 * 
 * Description: Given an array of integers nums and an integer threshold, 
 * find the smallest divisor such that the sum of the division results is <= threshold.
 * Each result of division is rounded up to the nearest integer (ceil).
 * 
 * Logic:
 * Divisor range: [1, max(nums)]
 * For divisor 'mid', sum = sum(ceil(nums[i] / mid)).
 * If sum <= threshold, mid is valid -> search smaller divisor (high = mid - 1).
 * Else -> search larger divisor (low = mid + 1).
 * 
 * Time Complexity: O(N * log(max(nums)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& arr, int threshold, int mid) {
        long long currSum = 0;
        for (int val : arr) {
            // Equivalent to ceil(val / (double)mid) using integer arithmetic
            currSum += (val + mid - 1) / mid;
            if (currSum > threshold) {
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int>& arr, int threshold) {
        int maxi = INT_MIN;
        for (int val : arr) {
            maxi = max(maxi, val);
        }

        int low = 1;
        int high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, threshold, mid)) {
                ans = mid;      // candidate answer found
                high = mid - 1; // look for smaller divisor
            } else {
                low = mid + 1;  // need larger divisor
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Array: {1, 2, 5, 9}, Threshold: " << threshold << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(nums, threshold) << " (expected 5)" << endl;

    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Smallest Divisor: " << sol.smallestDivisor(nums2, threshold2) << " (expected 44)" << endl;

    return 0;
}
