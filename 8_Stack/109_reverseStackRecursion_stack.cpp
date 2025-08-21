#include <iostream>
#include <stack>
using namespace std;

// Inserts x at the bottom of stack
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, x);  // Recursive call

    st.push(num);  // Push elements back after x is inserted at bottom
}

class Solution {
public:
    void reverse(stack<int> &St) {
        if (St.empty()) {
            return;
        }

        int num = St.top();
        St.pop();

        reverse(St);  // Reverse the smaller stack

        insertAtBottom(St, num);  // Insert current top at bottom
    }
};

// Print stack top to bottom
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Main function
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);  // Top -> 3

    cout << "Original Stack: ";
    printStack(st);  // prints 3 2 1

    // Reverse it
    Solution obj;
    obj.reverse(st);

    cout << "Reversed Stack: ";
    printStack(st);  // prints 1 2 3 (Top -> 1)

    return 0;
}
