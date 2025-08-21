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
Node* buildTree(Node *root){
    cout<<"Enter the data:";
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting int rigth "<<data<<endl;
    root->right = buildTree(root->right);



    return root;

}

int main(){


    Node* root = NULL;

    root = buildTree(root);




}