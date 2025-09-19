#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            } else if (ch == ')') {
                bool isRednt = true;
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRednt = false;
                    }
                    st.pop();
                }

                if (isRednt == true) {
                    return true; // Redundant found
                }

                if (!st.empty()) {
                    st.pop(); // remove matching '('
                }
            }
        }
        return false; // No redundancy found
    }
};

int main() {
    Solution sol;

    // Test cases
    string expr1 = "((a+b))";     // Redundant
    string expr2 = "(a+(b)/c)";   // Not redundant
    string expr3 = "(a+b*(c-d))"; // Not redundant
    string expr4 = "(a)";         // Redundant

    cout << "Expression: " << expr1 << " --> Redundant? " << (sol.checkRedundancy(expr1) ? "Yes" : "No") << endl;
    cout << "Expression: " << expr2 << " --> Redundant? " << (sol.checkRedundancy(expr2) ? "Yes" : "No") << endl;
    cout << "Expression: " << expr3 << " --> Redundant? " << (sol.checkRedundancy(expr3) ? "Yes" : "No") << endl;
    cout << "Expression: " << expr4 << " --> Redundant? " << (sol.checkRedundancy(expr4) ? "Yes" : "No") << endl;

    return 0;
}
