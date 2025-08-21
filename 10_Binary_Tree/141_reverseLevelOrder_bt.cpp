#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void reverseLevelOrder(Node* root) {
    if(root == nullptr) return;

    queue<Node*> q;
    stack<int> st;

    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        st.push(temp->data);

        // Note: push right first, then left
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }

    // Print in reverse
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
   // root->right->right = new Node(6);

    reverseLevelOrder(root);

   

}