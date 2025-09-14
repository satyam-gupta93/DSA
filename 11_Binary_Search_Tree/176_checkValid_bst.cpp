#include <iostream>
#include <climits>
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

bool solve(Node* root,long long minVal, long long maxVal){
    if(root==NULL){
        return true;
    }


    if(root->data < minVal || root->data > maxVal){
        return false;
    }

    return solve(root->left,minVal,root->data) && solve(root->right,root->data,maxVal);
}

bool checkValid(Node* root){
    if(root==NULL){
        return true;
    }

    return solve(root,LLONG_MIN,LLONG_MAX);
}

int main() {
    // Example Tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);


    cout<<"Is Valid:"<<checkValid(root)<<endl;
  

    return 0;
}
