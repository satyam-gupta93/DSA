#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 17. Minimum days to make M bouquets (LeetCode 1482)
 * Difficulty: Pro
 * 
 * Description: You are given an integer array bloomDay, an integer m and an integer k.
 * You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
 * The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] day.
 * Return the minimum number of days you need to wait to be able to make m bouquets from the garden.
 * If it is impossible to make m bouquets, return -1.
 * 
 * Logic:
 * Total flowers needed = (long long)m * k. If n < m * k, return -1.
 * Range of days: [1, max(bloomDay)].
 * On day 'mid', iterate through bloomDay:
 *  - Count consecutive bloomed flowers (bloomDay[i] <= mid).
 *  - Whenever count reaches k, bouquetCount++, reset count to 0.
 *  - If bloomDay[i] > mid, reset count to 0.
 * If bouquetCount >= m, day 'mid' is feasible -> search earlier day (high = mid - 1).
 * Else -> search later day (low = mid + 1).
 * 
 * Time Complexity: O(N * log(max(bloomDay)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& bD, int m, int k, int mid) {
        int count = 0;
        int bqt = 0;
        int n = bD.size();

        for (int i = 0; i < n; i++) {
            if (bD[i] <= mid) {
                count++;
                if (count == k) {
                    bqt++;
                    count = 0;
                }
            } else {
                count = 0;
            }

            if (bqt >= m) {
                return true;
            }
        }

        return bqt >= m;
    }

    int minDays(vector<int>& bD, int m, int k) {
        int n = bD.size();

        if (n < (long long)m * k) {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int val : bD) {
            mini = min(mini, val);
            maxi = max(maxi, val);
        }

        int low = mini;
        int high = maxi;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(bD, m, k, mid)) {
                ans = mid;
                high = mid - 1; // try to achieve in fewer days
            } else {
                low = mid + 1;  // need more days
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "BloomDay: {1, 10, 3, 10, 2}, m: 3, k: 1" << endl;
    cout << "Min days: " << sol.minDays(bloomDay, m, k) << " (expected 3)" << endl;

    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    cout << "BloomDay: {1, 10, 3, 10, 2}, m: 3, k: 2" << endl;
    cout << "Min days: " << sol.minDays(bloomDay2, m2, k2) << " (expected -1)" << endl;

    return 0;
}
