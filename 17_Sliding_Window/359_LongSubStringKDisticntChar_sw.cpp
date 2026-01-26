#include <bits/stdc++.h>
using namespace std;

// Given a string s and an integer k,
// find the length of the longest substring
// that contains exactly k distinct characters.
//
// Example:
// s = "aabacbebebe", k = 3
// Output: 7  -> "cbebebe"

// TC: O(n)
// SC: O(1)   
    int longestKSubstr(string &s, int k) {
        // code here
        int i = 0;
        int j = 0;
        int ans = -1;
        int n = s.size();
        unordered_map<char,int> m;
        
        
        while(j<n){
            m[s[j]]++;
            
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            
            if(m.size() == k){
                 ans = max(ans,j-i+1);
            }
            
           
            j++;
        }
        
        return ans;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;

    cout << longestKSubstr(s, k);
    return 0;
}
