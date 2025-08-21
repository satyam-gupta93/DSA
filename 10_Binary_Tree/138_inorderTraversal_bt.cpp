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

void inorderRecursive(Node *root){

    if(root==NULL){
        return;
    }

    inorderRecursive(root->left);
    cout<<root->data<<" ";
    inorderRecursive(root->right);
}


void inorderIterative(Node* root){
    if(root==NULL){
        return;
    }

    stack<Node*> st;
    Node* curr = root;

    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";

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

    cout<<"Inorder -> ";
    inorderRecursive(root);
    cout<<endl;
    cout<<"Inorder -> ";
    inorderIterative(root);


}