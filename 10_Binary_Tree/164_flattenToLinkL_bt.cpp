#include<iostream>
#include<stack>
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

void print(Node* root){
    Node* temp = root;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp -> right;
    }
}
void flattenLinkedList(Node* root){
    if(root==NULL){
        return;
    }

    Node* curr = root;

    while(curr){

        if(curr->left){
            Node* pred = curr->left;

            while(pred->right!=NULL && pred->right != curr){
                pred = pred ->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}



int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
   // root->right->right = new Node(6);

    cout<<"Flatten -> ";
   flattenLinkedList(root);
   print(root);
   
}