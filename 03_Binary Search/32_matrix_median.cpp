#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 32. Matrix Median (GFG / Striver)
 * Difficulty: Pro
 * 
 * Description: Given a row-wise sorted matrix of size R x C where R and C are odd numbers, 
 * find the median of the matrix.
 * Note: R * C is always odd, so there is exactly one median element.
 * 
 * Logic (Binary Search on Value Range):
 * 1. Range of numbers:
 *    low  = min(matrix[i][0])       for all rows i
 *    high = max(matrix[i][C - 1])   for all rows i
 * 2. For a candidate value 'mid':
 *    Count how many elements in the matrix are <= mid.
 *    Since each row is sorted, upper_bound on each row gives the count of elements <= mid in O(log C).
 *    totalCount = sum(upper_bound(row.begin(), row.end(), mid) - row.begin())
 * 3. In an array of size N = (R * C), the median has at least (N / 2 + 1) elements <= median.
 *    If totalCount <= (R * C) / 2:
 *      mid is too small -> low = mid + 1.
 *    Else:
 *      mid could be the median or larger -> high = mid - 1.
 * 4. The loop terminates when low > high; 'low' is the median.
 * 
 * Time Complexity: O(log(max - min) * R * log C)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int countLessOrEqual(const vector<vector<int>>& matrix, int mid) {
        int count = 0;
        for (const auto& row : matrix) {
            count += upper_bound(row.begin(), row.end(), mid) - row.begin();
        }
        return count;
    }

    int median(vector<vector<int>>& matrix, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < R; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        int required = (R * C) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countLessOrEqual(matrix, mid);

            if (count <= required) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int R = 3, C = 3;

    cout << "Matrix: 3x3" << endl;
    cout << "1 3 5\n2 6 9\n3 6 9" << endl;
    cout << "Matrix Median: " << sol.median(matrix, R, C) << " (expected 5)" << endl;

    return 0;
}
