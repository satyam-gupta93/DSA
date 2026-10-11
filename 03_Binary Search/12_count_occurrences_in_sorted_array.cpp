#include <iostream>
#include <vector>
using namespace std;

/*
 * 12. Count Occurrences in a Sorted Array (GFG)
 * Difficulty: Core
 * 
 * Description: Given a sorted array arr of N integers and a target x, 
 * find the number of occurrences of x in arr.
 * 
 * Logic:
 * Frequency = (lastOccurrence - firstOccurrence + 1) if target is present, else 0.
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int firstOccurrence(const vector<int>& arr, int x) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x) {
                ans = mid;
                e = mid - 1; // look in left half
            } else if (arr[mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }

    int lastOccurrence(const vector<int>& arr, int x) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == x) {
                ans = mid;
                s = mid + 1; // look in right half
            } else if (arr[mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);
        if (first == -1) {
            return 0;
        }
        int last = lastOccurrence(arr, target);
        return last - first + 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;

    cout << "Array: {1, 1, 2, 2, 2, 2, 3}, Target: " << target << endl;
    cout << "Count of " << target << ": " << sol.countFreq(arr, target) << " (expected 4)" << endl;

    int target2 = 4;
    cout << "Count of " << target2 << ": " << sol.countFreq(arr, target2) << " (expected 0)" << endl;

    return 0;
}
