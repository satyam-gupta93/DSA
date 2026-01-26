#include <bits/stdc++.h>
using namespace std;

// Given a string s consisting only of 'a', 'b', and 'c',
// return the number of substrings containing at least one
// occurrence of all three characters.


// TC: O(n)
// SC: O(1)
int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;

        vector<int> freq(3,0);
        int count = 0;

        int n = s.size();


        while( j< n ){
            freq[s[j] - 'a']++;

            while( freq[0]>0 && freq[1]>0 && freq[2]>0 ){
                count += (n-j);
                freq[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return count;

}

int main() {
    string s = "abcabc";
    cout << numberOfSubstrings(s);
    return 0;
}
