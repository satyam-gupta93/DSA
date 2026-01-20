#include <bits/stdc++.h>
using namespace std;

// Pick exactly k cards from either the start or the end.
// Example: [1,2,3,4,5,6,1], k = 3
// Best pick is [1,6,5] from the right side → sum = 12.



// TC: O(k)
// SC: O(1)
    int maxScore(vector<int>& cardPoints, int k) {

        int n =  cardPoints.size();
        int currSum = 0;
        int maxSum = 0;

        for(int i = 0; i<k; i++){
            currSum += cardPoints[i];
        }

        maxSum = currSum;
        int rightIndex = n - 1;

        for(int i = k -1; i>=0; i--){
            currSum -= cardPoints[i];
            currSum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(currSum,maxSum);
        }

        return maxSum;
    }

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << maxScore(cardPoints, k);
    return 0;
}
