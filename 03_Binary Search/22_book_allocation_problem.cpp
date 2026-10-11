#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * 22. Book Allocation Problem (GFG / Striver)
 * Difficulty: Pro
 * 
 * Description: Given an array nums of n books, where nums[i] is the number of pages in the ith book,
 * and an integer m representing the number of students.
 * Allocate all books to m students such that:
 *  1. Each student gets at least one book.
 *  2. Each book is allocated to only one student.
 *  3. Book allocation is contiguous.
 *  4. The maximum number of pages allocated to any student is minimized.
 * If allocation is impossible (e.g., m > n), return -1.
 * 
 * Time Complexity: O(N * log(sum - max))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& nums, int m, long long mid) {
        int studentCount = 1;
        long long pageSum = 0;

        for (int pages : nums) {
            if (pages > mid) {
                return false; // single book exceeds max limit
            }

            if (pageSum + pages <= mid) {
                pageSum += pages;
            } else {
                studentCount++;
                if (studentCount > m) {
                    return false;
                }
                pageSum = pages;
            }
        }

        return true;
    }

    long long findPages(vector<int>& nums, int m) {
        int n = nums.size();
        if (m > n) return -1; // more students than books

        int maxi = 0;
        long long sum = 0;
        for (int p : nums) {
            maxi = max(maxi, p);
            sum += p;
        }

        long long s = maxi;
        long long e = sum;
        long long ans = -1;

        while (s <= e) {
            long long mid = s + (e - s) / 2;

            if (isPossible(nums, m, mid)) {
                ans = mid;    // mid is feasible, try a smaller maximum limit
                e = mid - 1;
            } else {
                s = mid + 1;  // need a larger maximum limit
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    int m = 2;

    cout << "Books: {12, 34, 67, 90}, Students: " << m << endl;
    cout << "Minimum Maximum Pages: " << sol.findPages(books, m) << " (expected 113)" << endl;

    vector<int> books2 = {25, 46, 28, 49, 24};
    int m2 = 4;
    cout << "Books: {25, 46, 28, 49, 24}, Students: " << m2 << endl;
    cout << "Minimum Maximum Pages: " << sol.findPages(books2, m2) << " (expected 71)" << endl;

    return 0;
}
