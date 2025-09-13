#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorderKth(Node* root, int k, int &count, int &res) {
    if (root == NULL) return;

    inorderKth(root->left, k, count, res);

    count++;
    if (count == k) {
        res = root->data;
        return;
    }

    inorderKth(root->right, k, count, res);
}

int kthSmallest(Node* root, int k) {
    int count = 0;
    int res = -1; // default
    inorderKth(root, k, count, res);
    return res;
}

int main() {
    // Example Tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k = 3;
    cout << "Kth Smallest = " << kthSmallest(root, k) << endl;

    return 0;
}
