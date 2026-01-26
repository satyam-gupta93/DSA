#include <bits/stdc++.h>
using namespace std;

// Given a string s and an integer k,
// return the length of the longest substring that can be obtained
// by replacing at most k characters so that all characters are the same.
//
// Example:
// s = "ABAB", k = 2
// Output: 4
//
// s = "AABABBA", k = 1
// Output: 4  -> "AABA" or "ABBA"

// TC: O(n)
// SC: O(1)  (26-sized frequency array)
int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;

        vector<int> freq(26,0);

        int n = s.size();
        int maxFreq = 0;

        while(j<n){
            freq[s[j] - 'A']++;

            maxFreq = max(maxFreq,freq[s[j] - 'A']);

            while( (j-i+1) - maxFreq > k  ){
                freq[s[i] - 'A']--;
                i++;
            }

            ans = max(j-i+1,ans);   
            j++;
        }

        return ans;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);
    return 0;
}
