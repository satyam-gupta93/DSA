#include <iostream>
using namespace std;

/*
 * 14. Find Nth root of a number (GFG / Striver)
 * Difficulty: Core
 * 
 * Description: Given two numbers n and m, find the integer nth root of m.
 * If nth root is not an integer, return -1.
 * 
 * Helper Function:
 * Returns:
 *   1 if mid^n == m
 *   2 if mid^n > m (safely stops early to prevent integer overflow)
 *   0 if mid^n < m
 * 
 * Time Complexity: O(n * log m)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int checkPower(int n, int m, int mid) {
        long long mul = 1;
        for (int i = 0; i < n; i++) {
            mul *= mid;
            if (mul > m) {
                return 2; // mid^n > m
            }
        }
        if (mul == m) return 1;
        return 0;
    }

    int nthRoot(int n, int m) {
        if (m == 0) return 0;
        if (m == 1) return 1;

        int low = 1;
        int high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int status = checkPower(n, m, mid);

            if (status == 1) {
                return mid; // exact root found
            } else if (status == 2) {
                high = mid - 1; // mid^n > m
            } else {
                low = mid + 1;  // mid^n < m
            }
        }

        return -1; // no integer root exists
    }
};

int main() {
    Solution sol;
    cout << "3rd root of 27: " << sol.nthRoot(3, 27) << " (expected 3)" << endl;
    cout << "4th root of 69: " << sol.nthRoot(4, 69) << " (expected -1)" << endl;
    cout << "2nd root of 9:  " << sol.nthRoot(2, 9)  << " (expected 3)" << endl;

    return 0;
}
