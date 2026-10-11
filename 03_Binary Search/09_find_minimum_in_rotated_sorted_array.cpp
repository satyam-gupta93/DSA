#include <iostream>
#include <vector>
using namespace std;

/*
 * 09. Find Minimum in Rotated Sorted Array (LeetCode 153)
 * Difficulty: Core
 * 
 * Description: Given a sorted rotated array of unique elements, find the minimum element.
 * 
 * Logic:
 * Compare nums[mid] with nums[e]:
 *  - If nums[mid] > nums[e]: Minimum must lie in the right half (strictly after mid) -> s = mid + 1.
 *  - If nums[mid] <= nums[e]: Minimum is either at mid or to the left of mid -> e = mid.
 * Terminates when s == e, which points to the minimum element.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return nums[s];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums3 = {11, 13, 15, 17};

    cout << "Min in {3, 4, 5, 1, 2}: " << sol.findMin(nums1) << " (expected 1)" << endl;
    cout << "Min in {4, 5, 6, 7, 0, 1, 2}: " << sol.findMin(nums2) << " (expected 0)" << endl;
    cout << "Min in {11, 13, 15, 17}: " << sol.findMin(nums3) << " (expected 11)" << endl;

    return 0;
}
