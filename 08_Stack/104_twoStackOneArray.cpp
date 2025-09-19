#include <bits/stdc++.h> 
using namespace std;
class TwoStack {

public:
     int *arr;
    int top1;
    int top2;
    int size;
    
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        arr = new int[s];  // Allocate memory
        top1 = -1;
        top2 = s;
        
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top1 < top2-1 ){
        top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
                
        if(top1 < top2-1){
            top2--;
            arr[top2] = num;
        }

    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if((top1>=0)){
            int val = arr[top1];
            top1--;
            return val;
        }else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size){
            int val = arr[top2];
            top2++;
            return val;
        }else{
           return -1; 
        }
    }
};
int main() {
    TwoStack ts(10); // Create two stacks in one array of size 10

    ts.push1(2);
    ts.push1(3);
    ts.push2(4);

    cout << ts.pop1() << " "; // Output: 3
    cout << ts.pop2() << " "; // Output: 4
    cout << ts.pop2() << endl; // Output: -1

    return 0;
}