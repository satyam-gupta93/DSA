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

Node* LCA(Node* root, int n1, int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data==n2){
        return root;
    }

    Node* lAns = LCA(root->left,n1,n2);
    Node* rAns = LCA(root->right,n1,n2);

    if(lAns!=NULL && rAns!=NULL){
        return root;
    }else if(lAns==NULL && rAns!=NULL){
        return rAns;
    }else if(lAns!=NULL && rAns==NULL){
        return lAns;
    }else{
        return NULL;
    }
}


int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 

    Node* ans = LCA(root,2,3);

    cout<<"LCA:"<<ans->data;

    return 0;
} 