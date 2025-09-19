#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Helper function to generate unique permutations
void solve(vector<string>& ans, string& s, int index) {
    if (index >= s.size()) {
        ans.push_back(s);
        return;
    }

    unordered_set<char> used; // To skip duplicates at the same position

    for (int i = index; i < s.size(); i++) {
        if (used.count(s[i])) continue; // Skip duplicate characters

        used.insert(s[i]);
        swap(s[index], s[i]);         // Choose
        solve(ans, s, index + 1);     // Explore
        swap(s[index], s[i]);         // Un-choose (Backtrack)
    }
}

class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> ans;
        solve(ans, s, 0);
        return ans;
    }
};


int main() {
    Solution sol;
    string s = "AAB";
    vector<string> result = sol.findPermutation(s);

    for (string perm : result) {
        cout << perm << endl;
    }

    return 0;
}
