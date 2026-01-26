#include <bits/stdc++.h>
using namespace std;

// Given a string s, find the length of the longest substring
// without repeating characters.
//
// Example:
// s = "abcabcbb"
// Output: 3  -> "abc"
//
// s = "bbbbb"
// Output: 1  -> "b"

// TC: O(n)
// SC: O(1)   
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.size();

        unordered_map<char,int>mp;


        while(j<n){
            mp[s[j]]++;

            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}
