#include <iostream>
#include <stack>
using namespace std;

// Your recursive helper function
void solve(stack<int>& s, int count, int n) {
    if (count == n / 2) {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, count + 1, n);

    s.push(num);
}

// Your class and deleteMid function
class Solution {
  public:
    void deleteMid(stack<int>& s) {
        int count = 0;
        int n = s.size();
        solve(s, count, n);
    }
};

// Main function to test the code
int main() {
    stack<int> s;

    // Pushing elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // Top of stack

    Solution obj;
    obj.deleteMid(s);

    // Print stack after deleting middle
    cout << "Stack after deleting middle element:\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
