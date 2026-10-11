#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 20. Painter's Partition Problem (GFG / Striver)
 * Difficulty: Pro
 * 
 * Description: Given an array arr of length N representing board lengths, and an integer k 
 * representing the number of painters. Each painter takes 1 unit of time to paint 1 unit of board.
 * A board can only be painted by one painter and painters must paint contiguous boards.
 * Find the minimum time to paint all boards.
 * 
 * Time Complexity: O(N * log(sum - max))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& arr, int k, long long mid) {
        int painterCount = 1;
        long long currBoardSum = 0;

        for (int length : arr) {
            if (length > mid) {
                return false;
            }

            if (currBoardSum + length <= mid) {
                currBoardSum += length;
            } else {
                painterCount++;
                if (painterCount > k) {
                    return false;
                }
                currBoardSum = length;
            }
        }

        return true;
    }

    long long minTime(vector<int>& arr, int k) {
        int maxi = INT_MIN;
        long long sum = 0;

        for (int val : arr) {
            maxi = max(maxi, val);
            sum += val;
        }

        long long s = maxi;
        long long e = sum;
        long long ans = sum;

        while (s <= e) {
            long long mid = s + (e - s) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;    // time is feasible, try smaller max time
                e = mid - 1;
            } else {
                s = mid + 1;  // need more time per painter
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 5, 5, 5};
    int k = 2;

    cout << "Boards: {5, 5, 5, 5}, Painters: " << k << endl;
    cout << "Minimum Time: " << sol.minTime(arr, k) << " (expected 10)" << endl;

    vector<int> arr2 = {10, 20, 30, 40};
    int k2 = 2;
    cout << "Boards: {10, 20, 30, 40}, Painters: " << k2 << endl;
    cout << "Minimum Time: " << sol.minTime(arr2, k2) << " (expected 60)" << endl;

    return 0;
}
