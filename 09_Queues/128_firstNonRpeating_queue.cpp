#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
string FirstNonRepeating(string &s) {
    string ans;                    // To store the final answer
    queue<char> q;                 // Queue to keep track of characters in order
    unordered_map<char, int> count; // Map to store frequency of each character

    // Process each character of the stream one by one
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];    // Current character

        count[ch]++;       // Increase frequency of this character
        q.push(ch);        // Add character to the queue

        // Remove characters from the front of the queue if they repeat
        while (!q.empty()) {
            if (count[q.front()] > 1) { // If front char is repeating
                q.pop();                // Remove it from queue
            } else {
                // Front character is the first non-repeating
                ans.push_back(q.front());
                break;                  // Stop checking further
            }
        }

        // If no non-repeating character is found
        if (q.empty()) {
            ans.push_back('#');
        }
    }

    return ans; // Return the result string
}

};

int main() {
    Solution sol;
    string s = "aabc";  // You can change input here
    cout << sol.FirstNonRepeating(s) << endl;
    return 0;
}
