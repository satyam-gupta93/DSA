#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};
Node* top = NULL;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) cout << "Stack Underflow\n";
    else {
        cout << "Popped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void peek() {
    if (top == NULL) cout << "Stack Empty\n";
    else cout << "Top: " << top->data << endl;
}

int main() {
    push(10);
    push(20);
    peek(); // Top: 20
    pop();  // Popped: 20
    peek(); // Top: 10
}