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


int countLeaf(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left == NULL && root->right==NULL){
        cout<<root->data<<" ";
        return 1;
    }

    return countLeaf(root->left) + countLeaf(root->right);


}

int countLeafIterative(Node* root){
    if(root==NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left==NULL && temp->right==NULL){
            cout<<temp->data<<" ";
            count++;
        }

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    return count;
}


int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"Number of leaf:"<<countLeaf(root);
    cout<<endl;
     cout<<"Number of leaf:"<<countLeafIterative(root);


}