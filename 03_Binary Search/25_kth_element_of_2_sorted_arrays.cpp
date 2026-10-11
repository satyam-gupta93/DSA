#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 25. Kth Element of Two Sorted Arrays (GFG / Striver)
 * Difficulty: Pro
 * 
 * Description: Given two sorted arrays arr1 and arr2 of size n and m respectively, 
 * and an element k, find the element that would be at the kth position of the final 
 * combined sorted array (1-based index).
 * 
 * Logic (Binary Search on Partition):
 * We need to pick mid1 elements from arr1 and mid2 = (k - mid1) elements from arr2.
 * Range for mid1:
 *   low  = max(0, k - m)  (at most m elements can be picked from arr2)
 *   high = min(k, n)      (at most n elements can be picked from arr1, and at most k in total)
 * Valid partition condition:
 *   leftA <= rightB && leftB <= rightA
 * When valid, the kth element is max(leftA, leftB).
 * 
 * Time Complexity: O(log(min(N, M)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        int n = arr1.size();
        int m = arr2.size();

        // Ensure arr1 is the smaller array for efficiency
        if (n > m) {
            return kthElement(arr2, arr1, k);
        }

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;

            int leftA  = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
            int rightA = (mid1 == n) ? INT_MAX : arr1[mid1];

            int leftB  = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];
            int rightB = (mid2 == m) ? INT_MAX : arr2[mid2];

            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            } else if (leftA > rightB) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    cout << "arr1: {2, 3, 6, 7, 9}, arr2: {1, 4, 8, 10}, k = " << k << endl;
    cout << "5th Element: " << sol.kthElement(arr1, arr2, k) << " (expected 6)" << endl;

    vector<int> arr3 = {100, 112, 256, 349, 770};
    vector<int> arr4 = {72, 86, 113, 119, 265, 445, 892};
    int k2 = 7;
    cout << "7th Element: " << sol.kthElement(arr3, arr4, k2) << " (expected 256)" << endl;

    return 0;
}
