#include <iostream>
#include <vector>
using namespace std;

/*
 * 02. Lower Bound (GFG / Striver)
 * Difficulty: Core
 * 
 * Description: Given a sorted array of N integers and an integer target, 
 * find the smallest index 'i' such that arr[i] >= target.
 * If no such index exists, return N (the size of the array).
 * 
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int ans = arr.size(); // default if all elements < target

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] >= target) {
                ans = mid;     // candidate index found, try finding smaller on left
                e = mid - 1;
            } else {
                s = mid + 1;   // answer must be on the right
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int target = 8;

    cout << "Array: {1, 2, 3, 3, 5, 8, 8, 10, 10, 11}" << endl;
    cout << "Lower Bound index for " << target << " is: " << sol.lowerBound(arr, target) << " (expected 5)" << endl;

    int target2 = 9;
    cout << "Lower Bound index for " << target2 << " is: " << sol.lowerBound(arr, target2) << " (expected 7)" << endl;

    return 0;
}
