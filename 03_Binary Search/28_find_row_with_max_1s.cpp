#include <iostream>
#include <vector>
using namespace std;

/*
 * 28. Find Row with Maximum 1's (GFG)
 * Difficulty: Core
 * 
 * Description: Given a 2D array arr of size n x m consisting of 0s and 1s, where each row is sorted, 
 * find the 0-based index of the row that has the maximum number of 1s.
 * If no 1s exist in the entire matrix, return -1.
 * 
 * Logic:
 * In each sorted row of 0s and 1s, the first occurrence of 1 gives the count of 1s:
 *   countOf1s = m - firstIndex(1)
 * Using binary search on each row, we find the first index of 1 in O(log M).
 * 
 * Time Complexity: O(N * log M)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int firstOccurrenceOfOne(int row, const vector<vector<int>>& arr) {
        int m = arr[row].size();
        int low = 0;
        int high = m - 1;
        int ans = m; // default: no 1 found in this row

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[row][mid] == 1) {
                ans = mid;
                high = mid - 1; // look for earlier 1
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();

        int maxOnes = 0;
        int maxRowIndex = -1;

        for (int i = 0; i < n; i++) {
            int firstIdx = firstOccurrenceOfOne(i, arr);
            int count = m - firstIdx;

            if (count > maxOnes) {
                maxOnes = count;
                maxRowIndex = i;
            }
        }

        return maxRowIndex;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout << "Row with max 1s: " << sol.rowWithMax1s(mat) << " (expected 2)" << endl;

    vector<vector<int>> mat2 = {
        {0, 0},
        {0, 0}
    };
    cout << "Row with max 1s (all zeroes): " << sol.rowWithMax1s(mat2) << " (expected -1)" << endl;

    return 0;
}
