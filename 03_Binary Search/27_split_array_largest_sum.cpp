#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * 27. Split Array - Largest Sum (LeetCode 410)
 * Difficulty: Pro
 * 
 * Description: Given an integer array nums and an integer k, split nums into k non-empty 
 * contiguous subarrays such that the largest sum of any subarray is minimized.
 * Return the minimized largest sum of the split.
 * 
 * Note: Structurally identical to Painter's Partition and Book Allocation Problem!
 * 
 * Logic:
 * Range for largest subarray sum: [max(nums), sum(nums)].
 * For a limit 'mid':
 *   Greedily accumulate elements into current subarray.
 *   If adding nums[i] exceeds mid, start a new subarray (split++).
 *   If total subarrays needed > k, mid is too small -> low = mid + 1.
 *   Else mid is feasible -> high = mid - 1.
 * 
 * Time Complexity: O(N * log(sum(nums) - max(nums)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& nums, int k, long long mid) {
        int splitCount = 1;
        long long currSum = 0;

        for (int num : nums) {
            if (num > mid) {
                return false;
            }

            if (currSum + num <= mid) {
                currSum += num;
            } else {
                splitCount++;
                if (splitCount > k) {
                    return false;
                }
                currSum = num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int maxi = 0;
        long long sum = 0;

        for (int num : nums) {
            maxi = max(maxi, num);
            sum += num;
        }

        long long low = maxi;
        long long high = sum;
        long long ans = sum;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;      // mid is feasible, try smaller largest sum
                high = mid - 1;
            } else {
                low = mid + 1;  // need larger limit
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "Array: {7, 2, 5, 10, 8}, k = " << k << endl;
    cout << "Minimized Largest Sum: " << sol.splitArray(nums, k) << " (expected 18)" << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Minimized Largest Sum: " << sol.splitArray(nums2, k2) << " (expected 9)" << endl;

    return 0;
}
