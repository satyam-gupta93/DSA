#include <bits/stdc++.h>
using namespace std;

// Given two strings s1 and s2,
// find the minimum window in s1 such that
// s2 appears as a subsequence in that window.
//
// Example:
// s1 = "abcdebdde", s2 = "bde"
// Output: "bcde"


// TC: O(n^2)
// SC: O(1)
    string minWindow(string& s1, string& s2) {
        // Code here

        string ans = "";
        int n = s1.size();
        int m = s2.size();
        for(int s = 0; s<n; s++){
            int i = s;
            int j = 0;
            while(i<n && j<m){
                if(s1[i] == s2[j]){
                    j++;
                }
                i++;
            }
            
            if(j == m){
                string window = s1.substr(s,i-s);
                
                if(ans == "" || window.size() < ans.size()){
                    ans = window;
                }
            }
            
            
        }
        
        return ans;
}

int main() {
    string s1 = "abcdebdde";
    string s2 = "bde";

    cout << minWindow(s1, s2);
    return 0;
}
