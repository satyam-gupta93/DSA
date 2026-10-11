#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * 18. Capacity to Ship Packages Within D Days (LeetCode 1011)
 * Difficulty: Pro
 * 
 * Description: A conveyor belt has packages that must be shipped from one port to another within days days.
 * The ith package on the conveyor belt has a weight of weights[i].
 * Return the least weight capacity of the ship that will result in all packages being shipped within days.
 * 
 * Logic:
 * Range for capacity: [max(weights), sum(weights)].
 * Helper isPossible(weights, capacity, days):
 *   Greedily accumulate packages into current day. If adding next exceeds capacity,
 *   dayCount++, start new day with current package.
 *   If dayCount > days, return false.
 * 
 * Time Complexity: O(N * log(sum(weights) - max(weights)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& weights, int mid, int days) {
        int dayCount = 1;
        int weightSum = 0;

        for (int w : weights) {
            if (w > mid) {
                return false; // single package heavier than capacity
            }

            if (weightSum + w <= mid) {
                weightSum += w;
            } else {
                dayCount++;
                if (dayCount > days) {
                    return false;
                }
                weightSum = w;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int sum = 0;

        for (int w : weights) {
            maxi = max(maxi, w);
            sum += w;
        }

        int s = maxi;
        int e = sum;
        int ans = sum;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(weights, mid, days)) {
                ans = mid;    // capacity is sufficient, try smaller
                e = mid - 1;
            } else {
                s = mid + 1;  // need larger capacity
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "Weights: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, Days: " << days << endl;
    cout << "Minimum Ship Capacity: " << sol.shipWithinDays(weights, days) << " (expected 15)" << endl;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Minimum Ship Capacity: " << sol.shipWithinDays(weights2, days2) << " (expected 6)" << endl;

    return 0;
}
