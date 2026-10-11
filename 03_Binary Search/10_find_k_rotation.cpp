#include <iostream>
#include <vector>
using namespace std;

/*
 * 10. Find out how many times the array is rotated (GFG)
 * Difficulty: Core
 * 
 * Description: Given an array arr of distinct integers sorted in ascending order 
 * and rotated k times, find the rotation count 'k'.
 * 
 * Observation:
 * The number of rotations is equal to the index of the minimum element.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findKRotation(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        // If array is already fully sorted (not rotated)
        if (arr[s] < arr[e]) {
            return 0;
        }

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] > arr[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s; // index of the minimum element is the number of rotations
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {5, 1, 2, 3, 4};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> arr3 = {4, 5, 6, 7, 0, 1, 2};

    cout << "{5, 1, 2, 3, 4} rotated: " << sol.findKRotation(arr1) << " times (expected 1)" << endl;
    cout << "{1, 2, 3, 4, 5} rotated: " << sol.findKRotation(arr2) << " times (expected 0)" << endl;
    cout << "{4, 5, 6, 7, 0, 1, 2} rotated: " << sol.findKRotation(arr3) << " times (expected 4)" << endl;

    return 0;
}
