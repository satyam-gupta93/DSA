#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 21. Aggressive Cows (GFG / SPOJ)
 * Difficulty: Pro
 * 
 * Description: Given n stall positions on a number line, place k cows in these stalls 
 * such that the minimum distance between any two cows is as large as possible.
 * Return the maximum possible minimum distance.
 * 
 * Logic:
 * 1. Sort the stalls array.
 * 2. Search space for minimum distance: [1, stalls[n-1] - stalls[0]].
 * 3. For distance 'mid':
 *    - Place first cow at stalls[0].
 *    - Greedily place subsequent cows in the first stall that is at least 'mid' distance away.
 *    - If all k cows can be placed, 'mid' is feasible -> search larger distance (low = mid + 1).
 *    - Else -> search smaller distance (high = mid - 1).
 * 
 * Time Complexity: O(N * log N + N * log(max_dist))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& stalls, int k, int mid) {
        int cowCount = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= mid) {
                cowCount++;
                lastPos = stalls[i];
                if (cowCount == k) {
                    return true;
                }
            }
        }

        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(stalls, k, mid)) {
                ans = mid;     // mid distance is possible, try larger
                low = mid + 1;
            } else {
                high = mid - 1; // try smaller
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;

    cout << "Stalls: {0, 3, 4, 7, 10, 9}, Cows: " << k << endl;
    cout << "Max Minimum Distance: " << sol.aggressiveCows(stalls, k) << " (expected 3)" << endl;

    vector<int> stalls2 = {1, 2, 8, 4, 9};
    int k2 = 2;
    cout << "Stalls: {1, 2, 8, 4, 9}, Cows: " << k2 << endl;
    cout << "Max Minimum Distance: " << sol.aggressiveCows(stalls2, k2) << " (expected 8)" << endl;

    return 0;
}
