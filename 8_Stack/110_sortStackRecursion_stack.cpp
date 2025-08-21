#include <iostream>
#include <stack>
using namespace std;

// Your SortedStack class definition
class SortedStack {
public:
    stack<int> s;

    void sort();  // Function to sort the stack
};

// Helper function to insert element in sorted order
void sortInserted(stack<int>& s, int num) {
    if (s.empty() || s.top() < num) {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortInserted(s, num);

    s.push(n);
}

// Sort function
void SortedStack::sort() {
    if (s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    sort();

    sortInserted(s, num);
}

// Helper to print the stack from top to bottom
void printStack(stack<int> s) {
    cout << "Sorted Stack (Top to Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    SortedStack ss;

    // Push elements into the stack (unsorted)
    ss.s.push(3);
    ss.s.push(1);
    ss.s.push(2);
    ss.s.push(2);

    cout << "Original Stack (Top to Bottom): ";
    printStack(ss.s);  // Will display stack before sorting

    // Sort the stack
    ss.sort();

    // Print the sorted stack
    printStack(ss.s);  // Will display sorted stack
    
    return 0;
}
