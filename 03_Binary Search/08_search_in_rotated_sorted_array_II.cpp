#include <iostream>
#include <vector>
using namespace std;

/*
 * 08. Search in Rotated Sorted Array II (LeetCode 81)
 * Difficulty: Core
 * 
 * Description: Given an integer array nums sorted in ascending order (which may 
 * contain duplicates) and rotated at some pivot, return true if target exists 
 * in nums, or false otherwise.
 * 
 * Key Handling for Duplicates:
 * When nums[s] == nums[mid] && nums[mid] == nums[e], we cannot tell which half 
 * is sorted. We shrink the search space by s++ and e--.
 * 
 * Time Complexity: Average O(log N), Worst case O(N/2) (e.g. all elements identical)
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Ambiguity case: trim both ends
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }

            // Left half is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};

    cout << "Array: {2, 5, 6, 0, 0, 1, 2}" << endl;
    cout << "Search 0: " << (sol.search(nums, 0) ? "Found" : "Not Found") << " (expected Found)" << endl;
    cout << "Search 3: " << (sol.search(nums, 3) ? "Found" : "Not Found") << " (expected Not Found)" << endl;

    vector<int> nums2 = {3, 1, 2, 3, 3, 3, 3};
    cout << "Search 1 in {3, 1, 2, 3, 3, 3, 3}: " << (sol.search(nums2, 1) ? "Found" : "Not Found") << " (expected Found)" << endl;

    return 0;
}
