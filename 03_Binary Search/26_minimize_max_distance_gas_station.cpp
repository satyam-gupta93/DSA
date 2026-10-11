#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/*
 * 26. Minimize Max Distance to Gas Station (LeetCode 774 / GFG)
 * Difficulty: Pro
 * 
 * Description: You are given an integer array stations of length n, where stations[i] 
 * represents the position of the ith gas station along a horizontal road. 
 * You are also given an integer k. You want to add k more gas stations such that 
 * the maximum distance between adjacent gas stations is minimized.
 * Return the smallest possible value of the maximum distance.
 * 
 * Logic (Binary Search on Decimals):
 * Range for distance: [0, max(gap between adjacent stations)].
 * For a distance 'mid':
 *   Count additional stations needed: sum( (st[i+1] - st[i]) / mid )
 *   If count <= k, mid is achievable -> high = mid.
 *   Else -> low = mid.
 * Stop when (high - low) < 1e-6.
 * 
 * Time Complexity: O(N * log((max_dist) / 1e-6))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& st, int k, double mid) {
        int req = 0;
        int n = st.size();

        for (int i = 0; i < n - 1; i++) {
            double gap = st[i + 1] - st[i];
            req += (int)(gap / mid);
            if (req > k) {
                return false;
            }
        }

        return true;
    }

    double minMaxDist(vector<int>& st, int k) {
        int n = st.size();
        if (n <= 1) return 0.0;

        double maxi = 0;
        for (int i = 0; i < n - 1; i++) {
            maxi = max(maxi, (double)(st[i + 1] - st[i]));
        }

        double low = 0.0;
        double high = maxi;
        double diff = 1e-6;

        while (high - low > diff) {
            double mid = low + (high - low) / 2.0;

            if (isPossible(st, k, mid)) {
                high = mid; // feasible, try smaller distance
            } else {
                low = mid;  // not feasible, need larger distance
            }
        }

        return high;
    }
};

int main() {
    Solution sol;
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;

    cout << fixed << setprecision(6);
    cout << "Stations: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k = " << k << endl;
    cout << "Min Max Distance: " << sol.minMaxDist(stations, k) << " (expected 0.500000)" << endl;

    vector<int> stations2 = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
    int k2 = 2;
    cout << "Min Max Distance: " << sol.minMaxDist(stations2, k2) << " (expected 14.000000)" << endl;

    return 0;
}
