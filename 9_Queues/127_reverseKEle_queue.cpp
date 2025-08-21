#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (q.size() < k) {
            return q;
        }

        int count = k;
        stack<int> s;

        while (count--) {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        int r = q.size() - k;
        while (r--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }

        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // Sample input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    cout << "Original queue: ";
    {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
    }
    cout << endl;

    // Call function
    queue<int> result = sol.reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
