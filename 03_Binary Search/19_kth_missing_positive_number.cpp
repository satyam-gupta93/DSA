#include <iostream>
#include <vector>
using namespace std;

/*
 * 19. Kth Missing Positive Number (LeetCode 1539)
 * Difficulty: Pro
 * 
 * Description: Given an array arr of positive integers sorted in strictly 
 * ascending order, and an integer k. Return the kth positive integer that is missing from this array.
 * 
 * Logic:
 * In a normal array [1, 2, 3, ...], the element at index i should be (i + 1).
 * Therefore, at index mid, the number of missing numbers up to arr[mid] is:
 *   missing = arr[mid] - (mid + 1)
 * - If missing < k: The kth missing number lies to the right (s = mid + 1).
 * - Else: The kth missing number lies to the left (e = mid - 1).
 * After the loop finishes:
 *   The answer is s + k.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s + k;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Array: {2, 3, 4, 7, 11}, k = " << k << endl;
    cout << "5th Missing Positive Number: " << sol.findKthPositive(arr, k) << " (expected 9)" << endl;

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Array: {1, 2, 3, 4}, k = " << k2 << endl;
    cout << "2nd Missing Positive Number: " << sol.findKthPositive(arr2, k2) << " (expected 6)" << endl;

    return 0;
}
