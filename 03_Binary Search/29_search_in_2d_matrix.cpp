#include <iostream>
#include <vector>
using namespace std;

/*
 * 29. Search in a 2D Matrix (LeetCode 74)
 * Difficulty: Core
 * 
 * Description: You are given an m x n integer matrix with the following two properties:
 *  1. Each row is sorted in non-decreasing order.
 *  2. The first integer of each row is greater than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * Logic (Virtual 1D Flattening):
 * The entire matrix can be viewed as a 1D sorted array of length (n * m).
 * For any 1D index 'mid':
 *   row = mid / m
 *   col = mid % m
 *   element = matrix[row][col]
 * 
 * Time Complexity: O(log(N * M))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();

        int s = 0;
        int e = (n * m) - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int ele = matrix[mid / m][mid % m];

            if (ele == target) {
                return true;
            } else if (ele < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << "Search 3:  " << (sol.searchMatrix(matrix, 3) ? "Found" : "Not Found") << " (expected Found)" << endl;
    cout << "Search 13: " << (sol.searchMatrix(matrix, 13) ? "Found" : "Not Found") << " (expected Not Found)" << endl;

    return 0;
}
