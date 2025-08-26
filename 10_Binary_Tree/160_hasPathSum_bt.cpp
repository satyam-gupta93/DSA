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


bool hasPathSum(Node* root,int target){
    if(root==NULL){
        return false;
    }

    if(root->left==NULL && root->right==NULL){
        if(target==root->data){
            return true;
        }
        else{
            return false;
        }
    }

    return hasPathSum(root->left,target-root->data) || hasPathSum(root->right,target-root->data);
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

    if(hasPathSum(root,10)){
        cout<<"Yes!";
    }else{
         cout<<"No!";
    }


    return 0;
} 