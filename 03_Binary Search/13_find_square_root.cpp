#include <iostream>
using namespace std;

/*
 * 13. Find square root of a number (LeetCode 69 / GFG)
 * Difficulty: Core
 * 
 * Description: Given an integer n, find the floor of square root of n.
 * 
 * Logic:
 * Search space: [1, n].
 * For mid, check if mid * mid <= n:
 *  - If yes, mid is a candidate floor, try larger values in right half (low = mid + 1).
 *  - Else, mid * mid > n, search left half (high = mid - 1).
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;

        int low = 1;
        int high = n;
        int ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sqr = mid * mid;

            if (sqr <= n) {
                ans = mid;        // candidate floor
                low = mid + 1;    // try larger
            } else {
                high = mid - 1;   // try smaller
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout << "Square root of 25: " << sol.floorSqrt(25) << " (expected 5)" << endl;
    cout << "Square root of 28: " << sol.floorSqrt(28) << " (expected 5)" << endl;
    cout << "Square root of 36: " << sol.floorSqrt(36) << " (expected 6)" << endl;
    cout << "Square root of 0:  " << sol.floorSqrt(0)  << " (expected 0)" << endl;

    return 0;
}
