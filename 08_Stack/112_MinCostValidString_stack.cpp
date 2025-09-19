#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    int countMinReversals(string s) {
        // If length is odd, cannot be balanced
        if (s.length() % 2 != 0) return -1;

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '{') {
                st.push(ch);
            } else {
                if (!st.empty() && st.top() == '{') {
                    st.pop(); // Valid pair
                } else {
                    st.push(ch);
                }
            }
        }

        // Now stack contains only unbalanced brackets
        int a = 0, b = 0;
        while (!st.empty()) {
            if (st.top() == '{') a++;
            else b++;
            st.pop();
        }

        // Minimum reversals required
        return (a + 1) / 2 + (b + 1) / 2;
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "}{{}}{{{";
    string test2 = "{{{{";
    string test3 = "{{{{}}";
    string test4 = "}{}{}{";
    string test5 = "{{{}}}}";

    cout << "Expression: " << test1 << " --> Min Reversals: " << sol.countMinReversals(test1) << endl;
    cout << "Expression: " << test2 << " --> Min Reversals: " << sol.countMinReversals(test2) << endl;
    cout << "Expression: " << test3 << " --> Min Reversals: " << sol.countMinReversals(test3) << endl;
    cout << "Expression: " << test4 << " --> Min Reversals: " << sol.countMinReversals(test4) << endl;
    cout << "Expression: " << test5 << " --> Min Reversals: " << sol.countMinReversals(test5) << endl;

    return 0;
    
}
