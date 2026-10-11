#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 24. Median of Two Sorted Arrays (LeetCode 4)
 * Difficulty: Pro
 * 
 * Description: Given two sorted arrays nums1 and nums2 of size m and n respectively, 
 * return the median of the two sorted arrays in O(log(min(m, n))) runtime complexity.
 * 
 * Logic (Binary Search on Partition):
 * Partition nums1 into leftA (size mid1) and rightA (size n - mid1).
 * Partition nums2 into leftB (size mid2) and rightB (size m - mid2) such that:
 *   mid1 + mid2 = (n + m + 1) / 2
 * Valid partition condition:
 *   leftA <= rightB && leftB <= rightA
 * When valid:
 *   If total elements (n + m) is even:
 *     median = (max(leftA, leftB) + min(rightA, rightB)) / 2.0
 *   If odd:
 *     median = max(leftA, leftB)
 * If leftA > rightB: mid1 is too far right -> e = mid1 - 1
 * Else: mid1 is too far left -> s = mid1 + 1
 * 
 * Time Complexity: O(log(min(N, M)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Always perform binary search on the smaller array for O(log(min(n, m)))
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int s = 0;
        int e = n;

        while (s <= e) {
            int mid1 = s + (e - s) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int leftA  = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int rightA = (mid1 == n) ? INT_MAX : nums1[mid1];

            int leftB  = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int rightB = (mid2 == m) ? INT_MAX : nums2[mid2];

            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                } else {
                    return max(leftA, leftB);
                }
            } else if (leftA > rightB) {
                e = mid1 - 1;
            } else {
                s = mid1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "nums1: {1, 3}, nums2: {2}" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << " (expected 2.0)" << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "nums1: {1, 2}, nums2: {3, 4}" << endl;
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << " (expected 2.5)" << endl;

    return 0;
}
