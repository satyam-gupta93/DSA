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


void morrisTraversalInorder(Node* root){
    if(root==NULL){
        return;
    }

    Node* curr = root;

    while(curr!=NULL){

        // check left
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{  // if left==NULL

            // find inorder Predecor;
            Node* pred = curr->left;

            while(pred->right != NULL && pred->right!=curr){
                pred = pred->right;
            }

            // check if pred->right is NULL then make link to curr;
            if(pred->right==NULL){
                pred->right = curr;
                curr = curr->left;
            }else{ // already link exist
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

void morrisTraversalPreorder(Node* root) {
    if (root == NULL) return;

    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* pred = curr->left;

            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                // In Preorder we print BEFORE making thread
                cout << curr->data << " ";
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
   // root->right->right = new Node(6);

    cout<<"Inorder -> ";
    morrisTraversalInorder(root);
    cout<<endl;
  
    
    
    cout << "Preorder -> ";
    morrisTraversalPreorder(root);
    cout << endl;

}