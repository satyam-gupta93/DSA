#include <iostream>
#include <vector>
using namespace std;

/*
 * 31. Find Peak Element II (LeetCode 1901)
 * Difficulty: Core
 * 
 * Description: A peak element in a 2D grid is an element that is strictly greater than 
 * its 4 adjacent neighbors (left, right, top, bottom).
 * Given an m x n matrix mat where no two adjacent cells are equal, find any peak element 
 * and return its position {row, col}.
 * 
 * Logic (Binary Search on Columns):
 * 1. Binary search on column index: mid in range [0, m - 1].
 * 2. Find the row index 'maxRow' that has the maximum element in column 'mid'.
 * 3. Since mat[maxRow][mid] is the maximum in its column, it is guaranteed to be 
 *    strictly greater than both its top and bottom neighbors.
 * 4. We only need to compare it with its left and right neighbors:
 *    - If mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal:
 *        It is a 2D peak! Return {maxRow, mid}.
 *    - Else if mat[maxRow][mid] < leftVal:
 *        A peak must exist on the left side -> e = mid - 1.
 *    - Else:
 *        A peak must exist on the right side -> s = mid + 1.
 * 
 * Time Complexity: O(N * log M)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findMaxRowIndex(const vector<vector<int>>& mat, int col, int n) {
        int maxRow = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[maxRow][col]) {
                maxRow = i;
            }
        }
        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0;
        int e = m - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int maxRow = findMaxRowIndex(mat, mid, n);

            int leftVal  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < m)  ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            } else if (mat[maxRow][mid] < leftVal) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 4, 3},
        {6, 7, 5},
        {2, 3, 4}
    };

    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak element position: {" << peak[0] << ", " << peak[1] << "}" << endl;
    cout << "Peak value: " << mat[peak[0]][peak[1]] << " (expected 7 at {1, 1})" << endl;

    return 0;
}
