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


int getHeightRecursive(Node* root,int &d){
    if(root==NULL){
        return 0;
    }


    int l = getHeightRecursive(root->left,d); 
    int r = getHeightRecursive(root->right,d);

    d = max(d,l+r);


    return max(l,r) + 1;




}

int getDiameter(Node* root){
    int d = 0;
    getHeightRecursive(root,d);

    return d;
}

