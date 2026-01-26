#include <bits/stdc++.h>
using namespace std;

// You are given an array of fruits where fruits[i] represents the type of fruit.
// You can pick fruits from a contiguous subarray containing at most 2 types.
// Return the maximum number of fruits you can pick.
//
// Example:
// fruits = [1,2,1]
// Output: 3
//
// fruits = [0,1,2,2]
// Output: 3  -> [1,2,2]

// TC: O(n)
// SC: O(1)   (map size max = 2)
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int n = fruits.size();
        int i = 0;
        int j = 0;
       
        unordered_map<int,int> m;


        while(j<n){
            m[fruits[j]]++;

            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]] == 0){
                    m.erase(fruits[i]);
                }
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;



}

int main() {
    vector<int> fruits = {0, 1, 2, 2};
    cout << totalFruit(fruits);
    return 0;
}
