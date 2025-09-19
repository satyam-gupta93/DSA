#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        // Remove all elements greater than or equal to arr[i]
        while (s.top() >= arr[i]) {
            s.pop();
        }

        ans[i] = s.top();

        // Push current element to stack
        s.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
