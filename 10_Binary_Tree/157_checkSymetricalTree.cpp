#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool check(Node* t1,Node* t2){
    if(t1==NULL && t2==NULL){
        return true;
    }

    if(t1==NULL || t2==NULL){
        return false;
    }

    if(t1->data != t2->data){
        return false;
    }

    return check(t1->left,t2->right) && check(t1->right,t2->left);
}
    
bool checkSymmetric(Node* root){
    if(root==NULL){
        return true;
    }

    return check(root->left,root->right);
}
int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->right = new Node(6); 


    // Constructing a symmetric binary tree:
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);
    
    cout<<"Symmetric:"<<checkSymmetric(root);
   
    return 0;
} 