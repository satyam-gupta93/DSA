#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert x at the bottom
void solve(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    solve(st, x);
    st.push(num);
}

class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};

// Function to print a stack from top to bottom
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3); // Stack: Top->3 2 1->Bottom

    int x = 0;  // Element to insert at bottom

    Solution obj;
    stack<int> updatedStack = obj.insertAtBottom(st, x);

    cout << "Stack after inserting " << x << " at bottom: ";
    printStack(updatedStack); // Expected: 3 2 1 0 (top to bottom)

    return 0;
}
