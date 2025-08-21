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

void preOrderRecursive(Node* root){
    if(root==NULL){
        return; 
    }

    cout<<root->data<<" ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}
void preOrderIterative(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        cout<<temp->data<<" ";
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
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

    cout<<"PreOrder -> ";
    preOrderRecursive(root);
    cout<<endl;
    cout<<"PreOrder -> ";
    preOrderIterative(root);
   

}