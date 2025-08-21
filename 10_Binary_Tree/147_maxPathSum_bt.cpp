#include<iostream>
#include<queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int sumDown(Node* root,int &maxSum){
    if(root==NULL){
        return 0;
    }

    int ls = max(0,sumDown(root->left,maxSum));
    int rs = max(0,sumDown(root->right,maxSum));

    maxSum = max(maxSum,root->data+ls+rs);

    return root->data + max(ls,rs);
}

int maxPathSum(Node* root){
    if(root==NULL){
        return 0;
    }

    int maxSum = -564544;

    sumDown(root,maxSum);

    return maxSum;

}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"Max Path Sum:"<<maxPathSum(root);


}