#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t,
// return the minimum window substring of s such that
// every character in t (including duplicates) is included.
// If no such substring exists, return "".
//
// Example:
// s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

// TC: O(n)
// SC: O(1)   
   string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0; i<t.size(); i++){
            m[t[i]]++;
        }
        int missing = t.size();
        int start = 0;
        int minLen = INT_MAX;


        while(j<n){
            if(m[s[j]]>0){
                missing--;
            }

            m[s[j]]--;

            while(missing == 0){
                if((j-i+1)<minLen){
                    minLen = j - i +1;
                    start = i;
                }
                 m[s[i]]++;
                if(m[s[i]]>0){
                    missing++;
                }

               

                i++;
            }

            j++;
           
        }


        if(minLen == INT_MAX){
            return "";
        }else{
            return s.substr(start,minLen);
        }
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);
    return 0;
}
