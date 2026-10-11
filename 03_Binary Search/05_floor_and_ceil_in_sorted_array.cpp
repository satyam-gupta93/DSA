#include <iostream>
#include <vector>
using namespace std;

/*
 * 05. Floor and Ceil in Sorted Array (GFG / Striver)
 * Difficulty: Core
 * 
 * Description: Given a sorted array nums and an integer x:
 *  - Floor: the largest element in array <= x. (Returns -1 if no such element exists).
 *  - Ceil:  the smallest element in array >= x. (Returns -1 if no such element exists).
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

int findFloor(const vector<int>& nums, int x) {
    int s = 0, e = nums.size() - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] <= x) {
            ans = nums[mid];  // candidate floor found, look for larger in right half
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int findCeil(const vector<int>& nums, int x) {
    int s = 0, e = nums.size() - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] >= x) {
            ans = nums[mid];  // candidate ceil found, look for smaller in left half
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        return {findFloor(nums, x), findCeil(nums, x)};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 7, 8, 8, 10};
    int x = 5;

    vector<int> res = sol.getFloorAndCeil(nums, x);
    cout << "Array: {3, 4, 7, 8, 8, 10}, x = " << x << endl;
    cout << "Floor: " << res[0] << " (expected 4)" << endl;
    cout << "Ceil:  " << res[1] << " (expected 7)" << endl;

    return 0;
}
