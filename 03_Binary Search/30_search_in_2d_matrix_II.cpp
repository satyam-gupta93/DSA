#include <iostream>
#include <vector>
using namespace std;

/*
 * 30. Search in a 2D Matrix II (LeetCode 240)
 * Difficulty: Core
 * 
 * Description: Write an efficient algorithm that searches for a value target in an m x n 
 * integer matrix with properties:
 *  1. Integers in each row are sorted in ascending from left to right.
 *  2. Integers in each column are sorted in ascending from top to bottom.
 * 
 * Logic (Staircase Search):
 * Start at the top-right corner (row = 0, col = m - 1):
 *  - If current element == target: return true.
 *  - If current element > target: target cannot be in this entire column -> col--.
 *  - If current element < target: target cannot be in this entire row -> row++.
 * Can also start from bottom-left corner (row = n - 1, col = 0).
 * 
 * Time Complexity: O(N + M)
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();

        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // eliminate column
            } else {
                row++; // eliminate row
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    cout << "Search 5:  " << (sol.searchMatrix(matrix, 5) ? "Found" : "Not Found") << " (expected Found)" << endl;
    cout << "Search 20: " << (sol.searchMatrix(matrix, 20) ? "Found" : "Not Found") << " (expected Not Found)" << endl;

    return 0;
}
