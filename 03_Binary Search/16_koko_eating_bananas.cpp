#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 16. Koko eating bananas (LeetCode 875)
 * Difficulty: Pro
 * 
 * Description: Given n piles of bananas, where piles[i] is the number of bananas in the ith pile,
 * and h hours. Return the minimum integer speed k (bananas/hour) such that Koko can eat all 
 * bananas within h hours.
 * 
 * Logic:
 * Range for speed k: [1, max(piles)].
 * For a speed 'mid':
 *   hours = sum(ceil(pile / mid))
 * If hours <= h, mid is feasible -> try slower speed (e = mid - 1).
 * Else -> need faster speed (s = mid + 1).
 * 
 * Time Complexity: O(N * log(max(piles)))
 * Space Complexity: O(1)
 */

class Solution {
public:
    bool isPossible(const vector<int>& piles, int mid, int h) {
        long long hourCount = 0;

        for (int pile : piles) {
            hourCount += (1LL * pile + mid - 1) / mid; // ceil(pile / mid)
            if (hourCount > h) {
                return false;
            }
        }

        return hourCount <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int pile : piles) {
            maxi = max(maxi, pile);
        }

        int s = 1;
        int e = maxi;
        int ans = maxi;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(piles, mid, h)) {
                ans = mid;    // mid speed is enough, try slower speed
                e = mid - 1;
            } else {
                s = mid + 1;  // need faster speed
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Piles: {3, 6, 7, 11}, Hours: " << h << endl;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles, h) << " (expected 4)" << endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Minimum Eating Speed: " << sol.minEatingSpeed(piles2, h2) << " (expected 30)" << endl;

    return 0;
}
