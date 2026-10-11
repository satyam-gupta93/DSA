#include <iostream>
#include <vector>
using namespace std;

/*
 * 11. Single Element in a Sorted Array (LeetCode 540)
 * Difficulty: Core
 * 
 * Description: You are given a sorted array consisting of only integers where every 
 * element appears exactly twice, except for one element which appears exactly once.
 * Return the single element that appears only once.
 * 
 * Logic (Even-Odd Index Pattern):
 * - Before the single element:
 *     First instance of a pair is at an EVEN index, second at an ODD index (even, odd).
 * - After the single element:
 *     First instance is at an ODD index, second at an EVEN index (odd, even).
 * - Using (mid ^ 1):
 *     If mid is even, mid ^ 1 = mid + 1.
 *     If mid is odd,  mid ^ 1 = mid - 1.
 * If nums[mid] == nums[mid ^ 1], the pair pattern is unbroken -> single element is on right (s = mid + 1).
 * Else -> single element is at mid or on left (e = mid).
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == nums[mid ^ 1]) {
                s = mid + 1; // Left half is normal, answer is in right half
            } else {
                e = mid;     // Single element is at mid or left
            }
        }

        return nums[s];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};

    cout << "Array 1: {1, 1, 2, 3, 3, 4, 4, 8, 8}" << endl;
    cout << "Single Element: " << sol.singleNonDuplicate(nums1) << " (expected 2)" << endl;

    cout << "\nArray 2: {3, 3, 7, 7, 10, 11, 11}" << endl;
    cout << "Single Element: " << sol.singleNonDuplicate(nums2) << " (expected 10)" << endl;

    return 0;
}
